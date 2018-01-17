// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Simulation/SpecularSimulation.cpp
//! @brief     Implements class OffSpecSimulation.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#include "SpecularSimulation.h"
#include "IBackground.h"
#include "IFootprintFactor.h"
#include "IMultiLayerBuilder.h"
#include "MultiLayer.h"
#include "SpecularMatrix.h"
#include "MaterialUtils.h"
#include "Histogram1D.h"
#include "SimulationElement.h"
#include "SpecularComputation.h"
#include "SpecularDetector1D.h"

namespace
{
SpecularDetector1D* SpecDetector(Instrument& instrument);
}

SpecularSimulation::SpecularSimulation() : Simulation()
{
    initialize();
}

SpecularSimulation::SpecularSimulation(const MultiLayer& sample) : Simulation(sample)
{
    initialize();
}

SpecularSimulation::SpecularSimulation(const std::shared_ptr<IMultiLayerBuilder> sample_builder)
    : Simulation(sample_builder)
{
    initialize();
}

SpecularSimulation::SpecularSimulation(const SpecularSimulation& other)
    : Simulation(other)
    , m_sim_elements(other.m_sim_elements)
    , m_cache(other.m_cache)
{
    initialize();
}

SpecularSimulation::~SpecularSimulation() = default;

SpecularSimulation* SpecularSimulation::clone() const
{
    return new SpecularSimulation(*this);
}

void SpecularSimulation::prepareSimulation()
{
    if (m_instrument.getDetectorDimension() != 1) // detector must have only one axis
        throw std::runtime_error("Error in SpecularSimulation::prepareSimulation: the detector was "
                                 "not properly configured.");
    getInstrument().initDetector();
    Simulation::prepareSimulation();
}

size_t SpecularSimulation::numberOfSimulationElements() const
{
    return getInstrument().getDetector()->numberOfSimulationElements();
}

void SpecularSimulation::setBeamParameters(double lambda, const IAxis& alpha_axis, double phi_i)
{
    SpecularDetector1D detector(alpha_axis);
    m_instrument.setDetector(detector);
    m_instrument.setBeamParameters(lambda, alpha_axis[0], phi_i);
}

void SpecularSimulation::setBeamParameters(double lambda, int nbins, double alpha_i_min,
                                           double alpha_i_max, double phi_i)
{
    FixedBinAxis axis("alpha_i", nbins, alpha_i_min, alpha_i_max);
    setBeamParameters(lambda, axis, phi_i);
}

const IAxis* SpecularSimulation::getAlphaAxis() const
{
    return &m_instrument.getDetector()->getAxis(0);
}

void SpecularSimulation::initSimulationElementVector()
{
    auto beam = m_instrument.getBeam();
    m_sim_elements = generateSimulationElements(beam);
    if (m_cache.empty())
        m_cache = m_sim_elements;
}

std::vector<SimulationElement> SpecularSimulation::generateSimulationElements(const Beam& beam)
{
    auto p_detector = SpecDetector(m_instrument);
    return p_detector->createSimulationElements(beam);
}

std::vector<complex_t> SpecularSimulation::getData(size_t i_layer, DataGetter fn_ptr) const
{
    validityCheck(i_layer);
    std::vector<complex_t> result;
    const size_t data_size = m_sim_elements.size();
    result.resize(data_size);
    for (size_t i = 0; i < data_size; ++i) {
        const SpecularData* specular_data = m_sim_elements[i].specularData();
        result[i] = ((*specular_data)[i_layer].*fn_ptr)();
    }
    return result;
}

std::unique_ptr<OutputData<double>>
SpecularSimulation::getDataByAbsValue(size_t i_layer, DataGetter fn_ptr) const
{
    std::unique_ptr<OutputData<double>> output_ptr = std::make_unique<OutputData<double>>();
    output_ptr->addAxis(*getAlphaAxis());
    const std::vector<complex_t> complex_data = getData(i_layer, fn_ptr);
    OutputData<double>& output = *output_ptr.get();
    for (size_t i = 0; i < complex_data.size(); ++i)
        output[i] = std::norm(complex_data[i]);
    return output_ptr;
}

std::unique_ptr<IComputation>
SpecularSimulation::generateSingleThreadedComputation(size_t start, size_t n_elements)
{
    assert(start < m_sim_elements.size() && start + n_elements <= m_sim_elements.size());
    const auto& begin = m_sim_elements.begin() + static_cast<long>(start);
    return std::make_unique<SpecularComputation>(*sample(), m_options, m_progress, begin,
                                                 begin + static_cast<long>(n_elements));
}

OutputData<double>* SpecularSimulation::getDetectorIntensity(AxesUnits units_type) const
{
    const size_t i_layer = 0; // detector intensity is proportional to reflectivity from the zeroth layer
    validityCheck(i_layer);
    return m_instrument.createDetectorIntensity(m_sim_elements, units_type);
}

Histogram1D* SpecularSimulation::detectorIntensityHistogram() const
{
    std::unique_ptr<OutputData<double>> result(getDetectorIntensity());
    return new Histogram1D(*result);
}

Histogram1D* SpecularSimulation::transmissivity() const
{
    const MultiLayer* current_sample = sample();
    const size_t i_layer = current_sample ? static_cast<size_t>(current_sample->numberOfLayers() - 1) : 0;
    return new Histogram1D(*getDataByAbsValue(i_layer, &ILayerRTCoefficients::getScalarT));
}

std::vector<complex_t> SpecularSimulation::getScalarR(size_t i_layer) const
{
    return getData(i_layer, &ILayerRTCoefficients::getScalarR);
}

std::vector<complex_t> SpecularSimulation::getScalarT(size_t i_layer) const
{
    return getData(i_layer, &ILayerRTCoefficients::getScalarT);
}

std::vector<complex_t> SpecularSimulation::getScalarKz(size_t i_layer) const
{
    return getData(i_layer, &ILayerRTCoefficients::getScalarKz);
}

void SpecularSimulation::validityCheck(size_t i_layer) const
{
    const MultiLayer* current_sample = sample();
    if (!current_sample)
        throw std::runtime_error(
            "Error in SpecularSimulation::validityCheck: no sample found in the simulation.");
    if (i_layer >= current_sample->numberOfLayers())
        throw std::runtime_error("Error in SpecularSimulation::validityCheck: passed layer number "
                                 "exceeds the number of layers in the sample.");

    const size_t data_size = m_sim_elements.size();
    if (data_size != getAlphaAxis()->size())
        throw std::runtime_error("Error in SpecularSimulation::validityCheck: length of simulation "
                                 "element vector is not equal to the length of detector axis");

    for (size_t i = 0; i < data_size; ++i) {
        const SpecularData* specular_data = m_sim_elements[i].specularData();
        if (!specular_data || !specular_data->isInited()) {
            std::ostringstream message;
            message << "Error in SpecularSimulation::validityCheck: simulation element " << i << "does not contain specular info";
            throw std::runtime_error(message.str());
        }
    }
}

void SpecularSimulation::initialize()
{
    setName(BornAgain::SpecularSimulationType);
}

void SpecularSimulation::normalizeIntensity(size_t index, double beam_intensity)
{
    SimulationElement& element = m_sim_elements[index];
    const double alpha_i = -element.getAlphaI();
    const double footprint_coef = m_instrument.getBeam().footprintFactor().calculate(alpha_i);
    element.setIntensity(element.getIntensity() * beam_intensity * footprint_coef);
}

void SpecularSimulation::addBackGroundIntensity(size_t start_ind, size_t n_elements)
{
    if (!mP_background)
        return;
    for (size_t i = start_ind, stop_point = start_ind + n_elements; i < stop_point; ++i) {
        SimulationElement& element = m_sim_elements[i];
        mP_background->addBackGround(element);
    }
}

void SpecularSimulation::addDataToCache(double weight)
{
    assert(m_sim_elements.size() == m_cache.size());
    for (unsigned i=0; i<m_sim_elements.size(); i++) {
        m_cache[i].setIntensity(m_sim_elements[i].getIntensity()*weight);
        if (m_sim_elements[i].specularData()) {
            m_cache[i].setSpecular(std::unique_ptr<SpecularData>(
                                       m_sim_elements[i].specularData()->clone()));
        }
    }
}

void SpecularSimulation::moveDataFromCache()
{
    assert(!m_cache.empty());
    if (!m_cache.empty()) {
        m_sim_elements = std::move(m_cache);
        m_cache.clear();
    }
}

double SpecularSimulation::alpha_i(size_t index) const
{
    const IAxis* p_axis = getAlphaAxis();
    auto p_detector = m_instrument.getDetector();
    const size_t axis_index = p_detector->axisBinIndex(index, BornAgain::X_AXIS_INDEX);
    return p_axis->getBin(axis_index).getMidPoint();
}

namespace
{
SpecularDetector1D* SpecDetector(Instrument& instrument)
{
    SpecularDetector1D* detector = dynamic_cast<SpecularDetector1D*>(instrument.getDetector());
    if (!detector)
        throw std::runtime_error(
            "Error in SpecularSimulation: wrong detector type");
    return detector;
}
}

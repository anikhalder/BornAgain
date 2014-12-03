// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Samples/src/ParticleCollection.cpp
//! @brief     Implements class ParticleCollection.
//!
//! @homepage  http://apps.jcns.fz-juelich.de/BornAgain
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2013
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "ParticleCollection.h"
#include "ParticleInfo.h"


ParticleCollection::ParticleCollection(const IParticle &prototype,
                                       const ParameterDistribution &par_distr)
    : m_par_distribution(par_distr)
{
    mP_particle.reset(prototype.clone());
    setName("ParticleCollection");
    registerChild(mP_particle.get());
}

ParticleCollection *ParticleCollection::clone() const
{
    ParticleCollection *p_result = new ParticleCollection(*mP_particle,
                                                          m_par_distribution);
    return p_result;
}

ParticleCollection *ParticleCollection::cloneInvertB() const
{
    throw Exceptions::NotImplementedException("ParticleCollection::"
        "cloneInvertB: should never be called");
}

IFormFactor *ParticleCollection::createFormFactor(
        complex_t wavevector_scattering_factor) const {
    (void)wavevector_scattering_factor;
    throw Exceptions::NotImplementedException("ParticleCollection::"
        "createFormFactor: should never be called");
}

const IFormFactor *ParticleCollection::getSimpleFormFactor() const {
    throw Exceptions::NotImplementedException("ParticleCollection::"
        "getSimpleFormFactor: should never be called");
}

std::vector<ParticleInfo *>
ParticleCollection::generateParticleInfos(kvector_t position,
                                          double abundance) const
{
    std::vector<ParticleInfo *> result;
    ParameterPool *pool = mP_particle->createParameterTree();
    std::string main_par_name =
            m_par_distribution.getMainParameterName();
    std::vector<ParameterPool::parameter_t > main_par_matches =
            pool->getMatchedParameters(main_par_name);
    if (main_par_matches.size() != 1) {
        throw Exceptions::RuntimeErrorException(
                    "ParticleCollection::generateParticleInfos: "
                    "main parameter name matches nothing or more than "
                    "one parameter");
    }
    ParameterPool::parameter_t main_par = main_par_matches[0];
    double main_par_value = main_par.getValue();
    std::vector<ParameterSample> main_par_samples =
            m_par_distribution.generateSamples();
    std::vector<std::string> linked_par_names =
            m_par_distribution.getLinkedParameterNames();
    std::map<std::string, double> linked_par_ratio_map;
    for (size_t i=0; i<linked_par_names.size(); ++i) {
        std::vector<ParameterPool::parameter_t > linked_par_matches =
                pool->getMatchedParameters(linked_par_names[i]);
        if (linked_par_matches.size() != 1) {
            throw Exceptions::RuntimeErrorException(
                        "ParticleCollection::generateParticleInfos: "
                        "linked parameter name matches nothing or more than "
                        "one parameter");
        }
        ParameterPool::parameter_t linked_par = linked_par_matches[0];
        double linked_par_value = linked_par.getValue();
        double linked_ratio = main_par_value==0 ? 1.0
                              : linked_par_value/main_par_value;
        linked_par_ratio_map[linked_par_names[i]] = linked_ratio;
    }
    for (size_t i=0; i<main_par_samples.size(); ++i) {
        ParameterSample main_sample = main_par_samples[i];
        double particle_abundance = abundance*main_sample.weight;
        ParticleInfo *p_particle_info = new ParticleInfo(*mP_particle, position,
                                                         particle_abundance);
        ParameterPool *new_pool = p_particle_info->createParameterTree();
        int changed = new_pool->setMatchedParametersValue(
                    main_par_name, main_sample.value);
        if (changed != 1) {
            throw Exceptions::RuntimeErrorException(
                    "ParticleCollection::generateParticleInfos: "
                    "main parameter name matches nothing or more than "
                    "one parameter");
        }
        for (std::map<std::string, double>::const_iterator it =
             linked_par_ratio_map.begin(); it != linked_par_ratio_map.end();
             ++it) {
            double new_linked_value = main_sample.value * it->second;
            changed = new_pool->setMatchedParametersValue(it->first, new_linked_value);
            if (changed != 1) {
                throw Exceptions::RuntimeErrorException(
                        "ParticleCollection::generateParticleInfos: "
                        "linked parameter name matches nothing or more than "
                        "one parameter");
            }
        }
        result.push_back(p_particle_info);
    }
    return result;
}

void ParticleCollection::applyTransformationToSubParticles(
        const Geometry::Transform3D& transform)
{
    mP_particle->applyTransformation(transform);
    return;
}



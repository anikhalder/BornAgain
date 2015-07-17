// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      StandardSamples/ParticlesInSSCABuilder.cpp
//! @brief     Implements class ParticlesInSSCABuilder.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "SizeDistributionModelsBuilder.h"
#include "MultiLayer.h"
#include "ParticleLayout.h"
#include "Materials.h"
#include "Units.h"
#include "InterferenceFunctionRadialParaCrystal.h"
#include "FormFactorCylinder.h"
#include "Distributions.h"
#include "ParticleDistribution.h"


ISample *SizeDistributionDAModelBuilder::buildSample() const
{
        MultiLayer *multi_layer = new MultiLayer();

        HomogeneousMaterial m_ambience("Air", 0.0, 0.0);
        HomogeneousMaterial m_substrate("Substrate", 6e-6, 2e-8);
        HomogeneousMaterial m_particle("Particle", 6e-4, 2e-8);

        // cylindrical particle 1
        double radius1(5*Units::nanometer);
        double height1 = radius1;
        FormFactorCylinder cylinder_ff1(radius1, height1);
        Particle cylinder1(m_particle, cylinder_ff1);

        // cylindrical particle 2
        double radius2(8*Units::nanometer);
        double height2(radius2);
        FormFactorCylinder cylinder_ff2(radius2, height2);
        Particle cylinder2(m_particle, cylinder_ff2);

        // interference function
        InterferenceFunctionRadialParaCrystal interference(18.0*Units::nanometer, 1e3*Units::nanometer);
        FTDistribution1DGauss pdf(3*Units::nanometer);
        interference.setProbabilityDistribution(pdf);

        // assembling the sample
        ParticleLayout particle_layout;
        particle_layout.addParticle(cylinder1, 0.8);
        particle_layout.addParticle(cylinder2, 0.2);
        particle_layout.addInterferenceFunction(interference);

        Layer air_layer(m_ambience);
        air_layer.addLayout(particle_layout);
        Layer substrate_layer(m_substrate);

        multi_layer->addLayer(air_layer);
        multi_layer->addLayer(substrate_layer);
        return multi_layer;
}

// ----------------------------------------------------------------------------

ISample *SizeDistributionLMAModelBuilder::buildSample() const
{
    MultiLayer *multi_layer = new MultiLayer();

    HomogeneousMaterial m_ambience("Air", 0.0, 0.0);
    HomogeneousMaterial m_substrate("Substrate", 6e-6, 2e-8);
    HomogeneousMaterial m_particle("Particle", 6e-4, 2e-8);

    // cylindrical particle 1
    double radius1(5*Units::nanometer);
    double height1 = radius1;
    FormFactorCylinder cylinder_ff1(radius1, height1);
    Particle cylinder1(m_particle, cylinder_ff1);

    // cylindrical particle 2
    double radius2(8*Units::nanometer);
    double height2(radius2);
    FormFactorCylinder cylinder_ff2(radius2, height2);
    Particle cylinder2(m_particle, cylinder_ff2);

    // interference function1
    InterferenceFunctionRadialParaCrystal interference1(16.8*Units::nanometer, 1e3*Units::nanometer);
    FTDistribution1DGauss pdf(3 * Units::nanometer);
    interference1.setProbabilityDistribution(pdf);

    // interference function2
    InterferenceFunctionRadialParaCrystal interference2(22.8*Units::nanometer, 1e3*Units::nanometer);
    interference2.setProbabilityDistribution(pdf);

    // assembling the sample
    ParticleLayout particle_layout1;
    particle_layout1.addParticle(cylinder1, 0.8);
    particle_layout1.addInterferenceFunction(interference1);

    ParticleLayout particle_layout2;
    particle_layout2.addParticle(cylinder2, 0.2);
    particle_layout2.addInterferenceFunction(interference2);

    Layer air_layer(m_ambience);
    air_layer.addLayout(particle_layout1);
    air_layer.addLayout(particle_layout2);
    Layer substrate_layer(m_substrate);

    multi_layer->addLayer(air_layer);
    multi_layer->addLayer(substrate_layer);

    return multi_layer;
}

// ----------------------------------------------------------------------------

ISample *SizeDistributionSSCAModelBuilder::buildSample() const
{
    MultiLayer *multi_layer = new MultiLayer();

    HomogeneousMaterial m_ambience("Air", 0.0, 0.0);
    HomogeneousMaterial m_substrate("Substrate", 6e-6, 2e-8);
    HomogeneousMaterial m_particle("Particle", 6e-4, 2e-8);

    // cylindrical particle 1
    double radius1(5*Units::nanometer);
    double height1 = radius1;
    FormFactorCylinder cylinder_ff1(radius1, height1);
    Particle cylinder1(m_particle, cylinder_ff1);

    // cylindrical particle 2
    double radius2(8*Units::nanometer);
    double height2(radius2);
    FormFactorCylinder cylinder_ff2(radius2, height2);
    Particle cylinder2(m_particle, cylinder_ff2);

    // interference function
    InterferenceFunctionRadialParaCrystal interference(18.0*Units::nanometer, 1e3*Units::nanometer);
    FTDistribution1DGauss pdf(3*Units::nanometer);
    interference.setProbabilityDistribution(pdf);
    interference.setKappa(1.0);

    // assembling the sample
    ParticleLayout particle_layout;
    particle_layout.addParticle(cylinder1, 0.8);
    particle_layout.addParticle(cylinder2, 0.2);
    particle_layout.addInterferenceFunction(interference);
    particle_layout.setApproximation(ILayout::SSCA);

    Layer air_layer(m_ambience);
    air_layer.addLayout(particle_layout);
    Layer substrate_layer(m_substrate);

    multi_layer->addLayer(air_layer);
    multi_layer->addLayer(substrate_layer);

    return multi_layer;
}

// ----------------------------------------------------------------------------

ISample *CylindersInSSCABuilder::buildSample() const
{
    MultiLayer *multi_layer = new MultiLayer();

    HomogeneousMaterial air_material("Air", 0.0, 0.0);
    HomogeneousMaterial particle_material("Particle", 6e-4, 2e-8);

    Layer air_layer(air_material);

    InterferenceFunctionRadialParaCrystal *p_interference_function =
            new InterferenceFunctionRadialParaCrystal(15.0*Units::nanometer,
                    1e3*Units::nanometer);
    FTDistribution1DGauss pdf(5*Units::nanometer);
    p_interference_function->setProbabilityDistribution(pdf);
    p_interference_function->setKappa(4.02698);
    ParticleLayout particle_layout;

    FormFactorCylinder ff_cylinder(5.0*Units::nanometer, 5.0*Units::nanometer);
    Particle particle_prototype(particle_material, ff_cylinder);

    DistributionGaussian gauss(5.0*Units::nanometer, 1.25*Units::nanometer);
    ParameterDistribution par_distr("/Particle/FormFactorCylinder/radius", gauss, 30, 3.0);
    par_distr.linkParameter("/Particle/FormFactorCylinder/height");
    ParticleDistribution particle_collection(particle_prototype, par_distr);
    particle_layout.addParticle(particle_collection);

    particle_layout.addInterferenceFunction(p_interference_function);
    particle_layout.setApproximation(ILayout::SSCA);

    air_layer.addLayout(particle_layout);

    multi_layer->addLayer(air_layer);
    return multi_layer;
}
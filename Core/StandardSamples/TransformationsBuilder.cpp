// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      StandardSamples/TransformationsBuilder.cpp
//! @brief     Implements classes to build samples with different transformations.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "TransformationsBuilder.h"
#include "HomogeneousMaterial.h"
#include "FormFactorBox.h"
#include "Particle.h"
#include "ParticleLayout.h"
#include "Layer.h"
#include "MultiLayer.h"
#include "Rotations.h"


ISample *TransformBoxBuilder::buildSample() const
{
    HomogeneousMaterial mAmbience("Air", 0.0, 0.0);
    HomogeneousMaterial mMiddle("Teflon", 2.900e-6, 6.019e-9);
    HomogeneousMaterial mSubstrate("Substrate", 3.212e-6, 3.244e-8);

    HomogeneousMaterial mParticle("Ag", 1.245e-5, 5.419e-7);

    Particle box(mParticle, FormFactorBox(50, 20, 10));
    box.setRotation(RotationZ(90.*Units::degree));
    box.applyRotation(RotationY(90.*Units::degree));
    box.setPosition(kvector_t(0, 0, -40));

    ParticleLayout layout;
    layout.addParticle(box);

    Layer air_layer(mAmbience);
    Layer middle_layer(mMiddle, 100.0);
    middle_layer.addLayout(layout);
    Layer substrate(mSubstrate);

    MultiLayer *multi_layer = new MultiLayer();
    multi_layer->addLayer(air_layer);
    multi_layer->addLayer(middle_layer);
    multi_layer->addLayer(substrate);

    return multi_layer;
}

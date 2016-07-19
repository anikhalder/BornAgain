// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Core/Particles/MesoCrystal.h
//! @brief     Declares class MesoCrystal.
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef MESOCRYSTAL_H
#define MESOCRYSTAL_H

#include "IClusteredParticles.h"
#include "IParticle.h"

//! @class MesoCrystal
//! @ingroup samples
//! @brief A particle with an internal structure of smaller particles

class BA_CORE_API_ MesoCrystal : public IParticle
{
public:
    MesoCrystal(IClusteredParticles *p_particle_structure, IFormFactor *p_form_factor);
    MesoCrystal(const IClusteredParticles &particle_structure, IFormFactor &form_factor);

    virtual ~MesoCrystal();
    virtual MesoCrystal *clone() const;

    //! Returns a clone with inverted magnetic fields
    virtual MesoCrystal *cloneInvertB() const;

    //! Calls the ISampleVisitor's visit method
    virtual void accept(ISampleVisitor *visitor) const;

    virtual void setAmbientMaterial(const IMaterial& material);
    virtual const IMaterial* getAmbientMaterial() const;

    //! Create a form factor for this particle with an extra scattering factor
    virtual IFormFactor *createTransformedFormFactor(const IRotation* p_rotation,
                                                     kvector_t translation) const;

    //! @brief get the internal structure, which is in principle unbounded in
    //! space (eg.  an infinite crystal)
    const IClusteredParticles *getClusteredParticles() const;

private:
    //! Creates a form factor decorated with the IParticle's position/rotation
    IFormFactor *createTransformationDecoratedFormFactor(const IFormFactor &bare_ff,
                                                         const IRotation* p_rotation,
                                                         kvector_t translation) const;

    IClusteredParticles *mp_particle_structure;
    IFormFactor *mp_meso_form_factor;
    void initialize();
};

#endif // MESOCRYSTAL_H



// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      coregui/Models/ParticleCollectionItem.h
//! @brief     Defines class ParticleCollectionItem
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef PARTICLECOLLECTIONITEM_H
#define PARTICLECOLLECTIONITEM_H

#include "ParameterizedGraphicsItem.h"

#include <QStringList>

class BA_CORE_API_ ParticleCollectionItem : public ParameterizedGraphicsItem
{
    Q_OBJECT
public:
    explicit ParticleCollectionItem(ParameterizedItem *parent=0);
    ~ParticleCollectionItem() {}
    void insertChildItem(int row, ParameterizedItem *item);
};

#endif // PARTICLECOLLECTIONITEM_H

// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      coregui/Models/TransformationItem.h
//! @brief     Declares class TransformationItem
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#ifndef TRANSFORMATIONITEM_H
#define TRANSFORMATIONITEM_H

#include "SessionGraphicsItem.h"
#include <QVector>

class TransformationItem : public SessionGraphicsItem
{

public:
    static const QString P_ROT;
    explicit TransformationItem();
    virtual ~TransformationItem(){}
};


#endif // TRANSFORMATIONITEM_H


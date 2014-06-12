// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      Models/ParticleItem.cpp
//! @brief     Implements class ParticleItem.
//!
//! @homepage  http://apps.jcns.fz-juelich.de/BornAgain
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2013
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#include "FormFactorItems.h"
#include "FormFactors.h"
#include "Units.h"

/* ------------------------------------------------ */

const QString AnisoPyramidItem::P_LENGTH = "Length";
const QString AnisoPyramidItem::P_WIDTH = "Width";
const QString AnisoPyramidItem::P_HEIGHT = "Height";
const QString AnisoPyramidItem::P_ALPHA = "Alpha";

AnisoPyramidItem::AnisoPyramidItem(ParameterizedItem *parent)
    : FormFactorItem(QString("AnisoPyramid"), parent)
{
    setItemName("AnisoPyramid");
    registerProperty(P_LENGTH, 20.0);
    registerProperty(P_WIDTH, 16.0);
    registerProperty(P_HEIGHT, 13.0);
    registerProperty(P_ALPHA, 60.0);
}

IFormFactor *AnisoPyramidItem::createFormFactor() const
{
    return new FormFactorAnisoPyramid(
                getRegisteredProperty(P_LENGTH).toDouble(),
                getRegisteredProperty(P_WIDTH).toDouble(),
                getRegisteredProperty(P_HEIGHT).toDouble(),
                getRegisteredProperty(P_ALPHA).toDouble()*Units::degree
                );
}

/* ------------------------------------------------ */

const QString BoxItem::P_LENGTH = "Length";
const QString BoxItem::P_WIDTH = "Width";
const QString BoxItem::P_HEIGHT = "Height";

BoxItem::BoxItem(ParameterizedItem *parent)
    : FormFactorItem(QString("Box"), parent)
{
    setItemName("Box");
    registerProperty(P_LENGTH, 20.0);
    registerProperty(P_WIDTH, 16.0);
    registerProperty(P_HEIGHT, 13.0);
}

IFormFactor *BoxItem::createFormFactor() const
{
    return new FormFactorBox(
                getRegisteredProperty(P_LENGTH).toDouble(),
                getRegisteredProperty(P_WIDTH).toDouble(),
                getRegisteredProperty(P_HEIGHT).toDouble()
                );
}

/* ------------------------------------------------ */

const QString ConeItem::P_RADIUS = "Length";
const QString ConeItem::P_HEIGHT = "Width";
const QString ConeItem::P_ALPHA = "Height";

ConeItem::ConeItem(ParameterizedItem *parent)
    : FormFactorItem(QString("Cone"), parent)
{
    setItemName("Cone");
    registerProperty(P_RADIUS, 10.0);
    registerProperty(P_HEIGHT, 13.0);
    registerProperty(P_ALPHA, 60.0);
}

IFormFactor *ConeItem::createFormFactor() const
{
    return new FormFactorCone(
                getRegisteredProperty(P_RADIUS).toDouble(),
                getRegisteredProperty(P_HEIGHT).toDouble(),
                getRegisteredProperty(P_ALPHA).toDouble()*Units::degree
                );
}

/* ------------------------------------------------ */

const QString Cone6Item::P_RADIUS = "Length";
const QString Cone6Item::P_HEIGHT = "Width";
const QString Cone6Item::P_ALPHA = "Height";

Cone6Item::Cone6Item(ParameterizedItem *parent)
    : FormFactorItem(QString("Cone6"), parent)
{
    setItemName("Cone6");
    registerProperty(P_RADIUS, 10.0);
    registerProperty(P_HEIGHT, 13.0);
    registerProperty(P_ALPHA, 60.0);
}

IFormFactor *Cone6Item::createFormFactor() const
{
    return new FormFactorCone6(
                getRegisteredProperty(P_RADIUS).toDouble(),
                getRegisteredProperty(P_HEIGHT).toDouble(),
                getRegisteredProperty(P_ALPHA).toDouble()*Units::degree
                );
}

/* ------------------------------------------------ */

const QString CuboctahedronItem::P_LENGTH = "Length";
const QString CuboctahedronItem::P_HEIGHT = "Height";
const QString CuboctahedronItem::P_HEIGHT_RATIO = "HeightRatio";
const QString CuboctahedronItem::P_ALPHA = "Alpha";

CuboctahedronItem::CuboctahedronItem(ParameterizedItem *parent)
    : FormFactorItem(QString("Cuboctahedron"), parent)
{
    setItemName("Cuboctahedron");
    registerProperty(P_LENGTH, 20.0);
    registerProperty(P_HEIGHT, 13.0);
    registerProperty(P_HEIGHT_RATIO, 0.7);
    registerProperty(P_ALPHA, 60.0);
}

IFormFactor *CuboctahedronItem::createFormFactor() const
{
    return new FormFactorCuboctahedron(
                getRegisteredProperty(P_LENGTH).toDouble(),
                getRegisteredProperty(P_HEIGHT).toDouble(),
                getRegisteredProperty(P_HEIGHT_RATIO).toDouble(),
                getRegisteredProperty(P_ALPHA).toDouble()*Units::degree
                );
}

/* ------------------------------------------------ */

const QString CylinderItem::P_RADIUS = "Radius";
const QString CylinderItem::P_HEIGHT = "Height";

CylinderItem::CylinderItem(ParameterizedItem *parent)
    : FormFactorItem(QString("Cylinder"), parent)
{
    setItemName("Cylinder");
    registerProperty(P_RADIUS, 8.0);
    registerProperty(P_HEIGHT, 16.0);
}

IFormFactor *CylinderItem::createFormFactor() const
{
    return new FormFactorCylinder(
                getRegisteredProperty(P_RADIUS).toDouble(),
                getRegisteredProperty(P_HEIGHT).toDouble()
                );
}

/* ------------------------------------------------ */

const QString EllipsoidalCylinderItem::P_RADIUS_A = "Radius_a";
const QString EllipsoidalCylinderItem::P_RADIUS_B = "Radius_b";
const QString EllipsoidalCylinderItem::P_HEIGHT = "Height";

EllipsoidalCylinderItem::EllipsoidalCylinderItem(ParameterizedItem *parent)
    : FormFactorItem(QString("EllipsoidalCylinder"), parent)
{
    setItemName("EllipsoidalCylinder");
    registerProperty(P_RADIUS_A, 8.0);
    registerProperty(P_RADIUS_B, 13.0);
    registerProperty(P_HEIGHT, 16.0);
}

IFormFactor *EllipsoidalCylinderItem::createFormFactor() const
{
    return new FormFactorEllipsoidalCylinder(
                getRegisteredProperty(P_RADIUS_A).toDouble(),
                getRegisteredProperty(P_RADIUS_B).toDouble(),
                getRegisteredProperty(P_HEIGHT).toDouble()
                );
}

/* ------------------------------------------------ */

const QString FullSphereItem::P_RADIUS = "Radius";

FullSphereItem::FullSphereItem(ParameterizedItem *parent)
    : FormFactorItem(QString("FullSphere"), parent)
{
    setItemName("FullSphere");
    registerProperty(P_RADIUS, 8.0);
}

IFormFactor *FullSphereItem::createFormFactor() const
{
    return new FormFactorFullSphere(
                getRegisteredProperty(P_RADIUS).toDouble()
                );
}

/* ------------------------------------------------ */

const QString FullSpheroidItem::P_RADIUS = "Radius";
const QString FullSpheroidItem::P_HEIGHT = "Height";

FullSpheroidItem::FullSpheroidItem(ParameterizedItem *parent)
    : FormFactorItem(QString("FullSpheroid"), parent)
{
    setItemName("FullSpheroid");
    registerProperty(P_RADIUS, 10.0);
    registerProperty(P_HEIGHT, 13.0);
}

IFormFactor *FullSpheroidItem::createFormFactor() const
{
    return new FormFactorFullSpheroid(
                getRegisteredProperty(P_RADIUS).toDouble(),
                getRegisteredProperty(P_HEIGHT).toDouble()
                );
}

/* ------------------------------------------------ */

const QString HemiEllipsoidItem::P_RADIUS_A = "Radius_a";
const QString HemiEllipsoidItem::P_RADIUS_B = "Radius_b";
const QString HemiEllipsoidItem::P_HEIGHT = "Height";

HemiEllipsoidItem::HemiEllipsoidItem(ParameterizedItem *parent)
    : FormFactorItem(QString("HemiEllipsoid"), parent)
{
    setItemName("HemiEllipsoid");
    registerProperty(P_RADIUS_A, 10.0);
    registerProperty(P_RADIUS_B, 6.0);
    registerProperty(P_HEIGHT, 8.0);
}

IFormFactor *HemiEllipsoidItem::createFormFactor() const
{
    return new FormFactorHemiEllipsoid(
                getRegisteredProperty(P_RADIUS_A).toDouble(),
                getRegisteredProperty(P_RADIUS_B).toDouble(),
                getRegisteredProperty(P_HEIGHT).toDouble()
                );
}

/* ------------------------------------------------ */

const QString Prism3Item::P_LENGTH = "Length";
const QString Prism3Item::P_HEIGHT = "Height";

Prism3Item::Prism3Item(ParameterizedItem *parent)
    : FormFactorItem(QString("Prism3"), parent)
{
    setItemName("Prism3");
    registerProperty(P_LENGTH, 10.0);
    registerProperty(P_HEIGHT, 13.0);
}

IFormFactor *Prism3Item::createFormFactor() const
{
    return new FormFactorPrism3(
                getRegisteredProperty(P_LENGTH).toDouble(),
                getRegisteredProperty(P_HEIGHT).toDouble()
                );
}

/* ------------------------------------------------ */

const QString Prism6Item::P_RADIUS = "Radius";
const QString Prism6Item::P_HEIGHT = "Height";

Prism6Item::Prism6Item(ParameterizedItem *parent)
    : FormFactorItem(QString("Prism6"), parent)
{
    setItemName("Prism6");
    registerProperty(P_RADIUS, 5.0);
    registerProperty(P_HEIGHT, 11.0);
}

IFormFactor *Prism6Item::createFormFactor() const
{
    return new FormFactorPrism6(
                getRegisteredProperty(P_RADIUS).toDouble(),
                getRegisteredProperty(P_HEIGHT).toDouble()
                );
}

/* ------------------------------------------------ */

const QString PyramidItem::P_LENGTH = "Radius";
const QString PyramidItem::P_HEIGHT = "Height";
const QString PyramidItem::P_ALPHA = "Alpha";

PyramidItem::PyramidItem(ParameterizedItem *parent)
    : FormFactorItem(QString("Pyramid"), parent)
{
    setItemName("Pyramid");
    registerProperty(P_LENGTH, 18.0);
    registerProperty(P_HEIGHT, 13.0);
    registerProperty(P_ALPHA, 60.0);
}

IFormFactor *PyramidItem::createFormFactor() const
{
    return new FormFactorPyramid(
                getRegisteredProperty(P_LENGTH).toDouble(),
                getRegisteredProperty(P_HEIGHT).toDouble(),
                getRegisteredProperty(P_ALPHA).toDouble()*Units::degree
                );
}

/* ------------------------------------------------ */

const QString Ripple1Item::P_LENGTH = "Length";
const QString Ripple1Item::P_WIDTH = "Width";
const QString Ripple1Item::P_HEIGHT = "Height";

Ripple1Item::Ripple1Item(ParameterizedItem *parent)
    : FormFactorItem(QString("Ripple1"), parent)
{
    setItemName("Ripple1");
    registerProperty(P_LENGTH, 27.0);
    registerProperty(P_WIDTH, 20.0);
    registerProperty(P_HEIGHT, 14.0);
}

IFormFactor *Ripple1Item::createFormFactor() const
{
    return new FormFactorRipple1(
                getRegisteredProperty(P_LENGTH).toDouble(),
                getRegisteredProperty(P_WIDTH).toDouble(),
                getRegisteredProperty(P_HEIGHT).toDouble()
                );
}

/* ------------------------------------------------ */

const QString Ripple2Item::P_LENGTH = "Length";
const QString Ripple2Item::P_WIDTH = "Width";
const QString Ripple2Item::P_HEIGHT = "Height";
const QString Ripple2Item::P_ASYMMETRY = "Asymmetry";

Ripple2Item::Ripple2Item(ParameterizedItem *parent)
    : FormFactorItem(QString("Ripple2"), parent)
{
    setItemName("Ripple2");
    registerProperty(P_LENGTH, 36.0);
    registerProperty(P_WIDTH, 25.0);
    registerProperty(P_HEIGHT, 14.0);
    registerProperty(P_ASYMMETRY, 3.0);
}

IFormFactor *Ripple2Item::createFormFactor() const
{
    return new FormFactorRipple2(
                getRegisteredProperty(P_LENGTH).toDouble(),
                getRegisteredProperty(P_WIDTH).toDouble(),
                getRegisteredProperty(P_HEIGHT).toDouble(),
                getRegisteredProperty(P_ASYMMETRY).toDouble()
                );
}

/* ------------------------------------------------ */

const QString TetrahedronItem::P_LENGTH = "Length";
const QString TetrahedronItem::P_HEIGHT = "Height";
const QString TetrahedronItem::P_ALPHA = "Alpha";

TetrahedronItem::TetrahedronItem(ParameterizedItem *parent)
    : FormFactorItem(QString("Tetrahedron"), parent)
{
    setItemName("Tetrahedron");
    registerProperty(P_LENGTH, 15.0);
    registerProperty(P_HEIGHT, 6.0);
    registerProperty(P_ALPHA, 60.0);
}

IFormFactor *TetrahedronItem::createFormFactor() const
{
    return new FormFactorTetrahedron(
                getRegisteredProperty(P_LENGTH).toDouble(),
                getRegisteredProperty(P_HEIGHT).toDouble(),
                getRegisteredProperty(P_ALPHA).toDouble()*Units::degree
                );
}

/* ------------------------------------------------ */

const QString TruncatedSphereItem::P_RADIUS = "Radius";
const QString TruncatedSphereItem::P_HEIGHT = "Height";

TruncatedSphereItem::TruncatedSphereItem(ParameterizedItem *parent)
    : FormFactorItem(QString("TruncatedSphere"), parent)
{
    setItemName("TruncatedSphere");
    registerProperty(P_RADIUS, 5.0);
    registerProperty(P_HEIGHT, 7.0);
}

IFormFactor *TruncatedSphereItem::createFormFactor() const
{
    return new FormFactorTruncatedSphere(
                getRegisteredProperty(P_RADIUS).toDouble(),
                getRegisteredProperty(P_HEIGHT).toDouble()
                );
}

/* ------------------------------------------------ */

const QString TruncatedSpheroidItem::P_RADIUS = "Radius";
const QString TruncatedSpheroidItem::P_HEIGHT = "Height";
const QString TruncatedSpheroidItem::P_HFC = "Hfc";

TruncatedSpheroidItem::TruncatedSpheroidItem(ParameterizedItem *parent)
    : FormFactorItem(QString("TruncatedSpheroid"), parent)
{
    setItemName("TruncatedSpheroid");
    registerProperty(P_RADIUS, 7.5);
    registerProperty(P_HEIGHT, 9.0);
    registerProperty(P_HFC, 1.2);
}

IFormFactor *TruncatedSpheroidItem::createFormFactor() const
{
    return new FormFactorTruncatedSpheroid(
                getRegisteredProperty(P_RADIUS).toDouble(),
                getRegisteredProperty(P_HEIGHT).toDouble(),
                getRegisteredProperty(P_HFC).toDouble()
                );
}



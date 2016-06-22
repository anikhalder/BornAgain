// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Models/IntensityDataItem.cpp
//! @brief     Implements class IntensityDataItem
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#include "IntensityDataItem.h"
#include "ComboProperty.h"
#include "AngleProperty.h"
#include "AxesItems.h"
#include "Units.h"
#include "GUIHelpers.h"
#include "GISASSimulation.h"
#include "BornAgainNamespace.h"
#include "IDetector2D.h"
#include "SphericalDetector.h"
#include "RectangularDetector.h"
#include <QDebug>

const QString IntensityDataItem::P_AXES_UNITS = "Axes Units";
const QString IntensityDataItem::P_PROJECTIONS_FLAG = "Projections";
const QString IntensityDataItem::P_IS_INTERPOLATED = "Interpolation";
const QString IntensityDataItem::P_GRADIENT = "Gradient";
const QString IntensityDataItem::P_PROPERTY_PANEL_FLAG = "Property Panel Flag";
const QString IntensityDataItem::P_XAXIS = "x-axis";
const QString IntensityDataItem::P_YAXIS = "y-axis";
const QString IntensityDataItem::P_ZAXIS = "color-axis";
const QString IntensityDataItem::P_FILE_NAME = "FileName";
const QString IntensityDataItem::T_MASKS = "Mask tag";


IntensityDataItem::IntensityDataItem()
    : SessionItem(Constants::IntensityDataType)
{
//    setItemName(Constants::IntensityDataType);

    ComboProperty units;
    addProperty(P_AXES_UNITS, units.getVariant())->setVisible(false);

    addProperty(P_PROJECTIONS_FLAG, false)->setVisible(false);
    addProperty(P_IS_INTERPOLATED, true);

    ComboProperty gradient;

    gradient << Constants::GRADIENT_GRAYSCALE << Constants::GRADIENT_HOT
             << Constants::GRADIENT_COLD << Constants::GRADIENT_NIGHT
             << Constants::GRADIENT_CANDY << Constants::GRADIENT_GEOGRAPHY
             << Constants::GRADIENT_ION << Constants::GRADIENT_THERMAL
             << Constants::GRADIENT_POLAR << Constants::GRADIENT_SPECTRUM
             << Constants::GRADIENT_JET << Constants::GRADIENT_HUES;
    gradient.setValue(Constants::GRADIENT_JET);
    addProperty(P_GRADIENT, gradient.getVariant());

    addProperty(P_PROPERTY_PANEL_FLAG, false)->setVisible(false);

    SessionItem *item = addGroupProperty(P_XAXIS, Constants::BasicAxisType);
    item->getItem(BasicAxisItem::P_NBINS)->setVisible(false);

    item = addGroupProperty(P_YAXIS, Constants::BasicAxisType);
    item->getItem(BasicAxisItem::P_NBINS)->setVisible(false);

    item = addGroupProperty(P_ZAXIS, Constants::AmplitudeAxisType);
    item->getItem(BasicAxisItem::P_NBINS)->setVisible(false);

    // name of the file used to serialize given IntensityDataItem
    addProperty(P_FILE_NAME, QStringLiteral("undefined"))->setVisible(false);

    registerTag(T_MASKS, 0, -1, QStringList() << Constants::MaskContainerType);
    setDefaultTag(T_MASKS);
}

IntensityDataItem::~IntensityDataItem()
{

}

void IntensityDataItem::setOutputData(OutputData<double> *data)
{
    Q_ASSERT(data);
    m_data.reset(data);

    initAxesZoomLevel();
    initAxesLabels();
    initDataRange();

    emitDataChanged();
}

//! Sets the raw data vector from external source

void IntensityDataItem::setRawDataVector(const OutputData<double> *data)
{
    if(!m_data->hasSameDimensions(*data)) {
        throw GUIHelpers::Error("IntensityDataItem::setRawDataVector() -> Error. "
                                "Different dimensions of data.");
    }
    m_data->setRawDataVector(data->getRawDataVector());
    emitDataChanged();
}

double IntensityDataItem::getLowerX() const
{
    return getItem(P_XAXIS)->getItemValue(BasicAxisItem::P_MIN).toDouble();
}

double IntensityDataItem::getUpperX() const
{
    return getItem(P_XAXIS)->getItemValue(BasicAxisItem::P_MAX).toDouble();
}

double IntensityDataItem::getXmin() const
{
    Q_ASSERT(m_data);
    return m_data->getAxis(BornAgain::X_AXIS_INDEX)->getMin();
}

double IntensityDataItem::getXmax() const
{
    Q_ASSERT(m_data);
    return m_data->getAxis(BornAgain::X_AXIS_INDEX)->getMax();
}

double IntensityDataItem::getLowerY() const
{
    return getItem(P_YAXIS)->getItemValue(BasicAxisItem::P_MIN).toDouble();
}

double IntensityDataItem::getUpperY() const
{
    return getItem(P_YAXIS)->getItemValue(BasicAxisItem::P_MAX).toDouble();
}

double IntensityDataItem::getYmin() const
{
    Q_ASSERT(m_data);
    return m_data->getAxis(BornAgain::Y_AXIS_INDEX)->getMin();
}

double IntensityDataItem::getYmax() const
{
    Q_ASSERT(m_data);
        return m_data->getAxis(BornAgain::Y_AXIS_INDEX)->getMax();
}

double IntensityDataItem::getLowerZ() const
{
    return getItem(P_ZAXIS)->getItemValue(BasicAxisItem::P_MIN).toDouble();
}

double IntensityDataItem::getUpperZ() const
{
    return getItem(P_ZAXIS)->getItemValue(BasicAxisItem::P_MAX).toDouble();
}

QString IntensityDataItem::getGradient() const
{
    ComboProperty combo_property = getItemValue(P_GRADIENT).value<ComboProperty>();
    return combo_property.getValue();
}

bool IntensityDataItem::isLogz() const
{
    return getItem(P_ZAXIS)->getItemValue(AmplitudeAxisItem::P_IS_LOGSCALE).toBool();
}

bool IntensityDataItem::isInterpolated() const
{
    return getItemValue(P_IS_INTERPOLATED).toBool();
}

QString IntensityDataItem::getXaxisTitle() const
{
    return getItem(P_XAXIS)->getItemValue(BasicAxisItem::P_TITLE).toString();
}

QString IntensityDataItem::getYaxisTitle() const
{
    return getItem(P_YAXIS)->getItemValue(BasicAxisItem::P_TITLE).toString();
}

bool IntensityDataItem::isZAxisLocked() const
{
    return getItem(P_ZAXIS)->getItemValue(AmplitudeAxisItem::P_LOCK_MIN_MAX).toBool();
}

void IntensityDataItem::setZAxisLocked(bool state)
{
    return getItem(P_ZAXIS)->setItemValue(AmplitudeAxisItem::P_LOCK_MIN_MAX, state);
}

QString IntensityDataItem::getSelectedAxesUnits() const
{
    ComboProperty combo= getItemValue(IntensityDataItem::P_AXES_UNITS)
              .value<ComboProperty>();
    return combo.getValue();
}

QString IntensityDataItem::fileName(const QString &projectDir)
{
    return projectDir + QStringLiteral("/")
           + getItemValue(IntensityDataItem::P_FILE_NAME).toString();
}

void IntensityDataItem::setLowerX(double xmin)
{
    getItem(P_XAXIS)->setItemValue(BasicAxisItem::P_MIN, xmin);
}

void IntensityDataItem::setUpperX(double xmax)
{
    getItem(P_XAXIS)->setItemValue(BasicAxisItem::P_MAX, xmax);
}

void IntensityDataItem::setLowerY(double ymin)
{
    getItem(P_YAXIS)->setItemValue(BasicAxisItem::P_MIN, ymin);
}

void IntensityDataItem::setUpperY(double ymax)
{
    getItem(P_YAXIS)->setItemValue(BasicAxisItem::P_MAX, ymax);
}

void IntensityDataItem::setLowerAndUpperZ(double zmin, double zmax)
{
    if(getLowerZ() != zmin) {
        getItem(P_ZAXIS)->setItemValue(BasicAxisItem::P_MIN, zmin);
    }
    if(getUpperZ() != zmax) {
        getItem(P_ZAXIS)->setItemValue(BasicAxisItem::P_MAX, zmax);
    }
}

void IntensityDataItem::setLowerZ(double zmin)
{
    getItem(P_ZAXIS)->setItemValue(BasicAxisItem::P_MIN, zmin);
}

void IntensityDataItem::setUpperZ(double zmax)
{
    getItem(P_ZAXIS)->setItemValue(BasicAxisItem::P_MAX, zmax);
}

void IntensityDataItem::setLogz(bool logz)
{
    getItem(P_ZAXIS)->setItemValue(AmplitudeAxisItem::P_IS_LOGSCALE, logz);
}

void IntensityDataItem::setInterpolated(bool interp)
{
    setItemValue(P_IS_INTERPOLATED, interp);
}

void IntensityDataItem::setXaxisTitle(QString xtitle)
{
    getItem(P_XAXIS)->setItemValue(BasicAxisItem::P_TITLE, xtitle);
}

void IntensityDataItem::setYaxisTitle(QString ytitle)
{
    getItem(P_YAXIS)->setItemValue(BasicAxisItem::P_TITLE, ytitle);
}

//! set zoom range of x,y axes to axes of input data
void IntensityDataItem::setAxesRangeToData()
{
    setLowerX(getXmin());
    setUpperX(getXmax());
    setLowerY(getYmin());
    setUpperY(getYmax());
}

//! Sets zoom range of X,Y axes, if it was not yet defined.

void IntensityDataItem::initAxesZoomLevel()
{
    // set zoom range of x-axis to min, max values if it was not set already
    if(getUpperX() < getLowerX()) {
        setLowerX(getXmin());
        setUpperX(getXmax());
    }

    // set zoom range of y-axis to min, max values if it was not set already
    if(getUpperY() < getLowerY()) {
        setLowerY(getYmin());
        setUpperY(getYmax());
    }

}

//! Init axes labels, if it was not done already.

void IntensityDataItem::initAxesLabels()
{
    if(getXaxisTitle().isEmpty())
        setXaxisTitle(QString::fromStdString(m_data->getAxis(BornAgain::X_AXIS_INDEX)->getName()));

    if(getYaxisTitle().isEmpty())
        setYaxisTitle(QString::fromStdString(m_data->getAxis(BornAgain::Y_AXIS_INDEX)->getName()));
}

void IntensityDataItem::initDataRange()
{
    if(isZAxisLocked())
        return;

    if(getLowerZ() <= getUpperZ())
        return;

    QPair<double, double> minmax = calculateDataRange();
    setLowerAndUpperZ(minmax.first, minmax.second);
}

//! Init zmin, zmax to match the intensity values range.
QPair<double, double> IntensityDataItem::calculateDataRange()
{
    const OutputData<double> *data = getOutputData();
    OutputData<double>::const_iterator it_max = std::max_element(data->begin(), data->end());
    OutputData<double>::const_iterator it_min = std::min_element(data->begin(), data->end());
    double min(*it_min), max(*it_max);
    if (isLogz()) {
        if (max > 10000) {
            min = 1.0;
            max = max * 1.1;
        } else {
            min = max / 10000;
            max = max * 1.1;
        }
    } else {
        max = max * 1.1;
    }

    return QPair<double, double>(min, max);
}

// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/IntensityDataWidgets/ProjectionCanvas.h
//! @brief     Defines class ProjectionCanvas
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#ifndef PROJECTIONCANVAS_H
#define PROJECTIONCANVAS_H

#include "SessionItemWidget.h"

class QCustomPlot;

//! A customplot based widget to display projections of IntensityDataItem on X,Y axes.

class BA_CORE_API_ ProjectionCanvas : public SessionItemWidget
{
    Q_OBJECT

public:
    ProjectionCanvas(QWidget* parent = 0);

    void setItem(SessionItem* projectionContainerItem);

private:
    QCustomPlot* m_customPlot;
};

#endif // PROJECTIONCANVAS_H
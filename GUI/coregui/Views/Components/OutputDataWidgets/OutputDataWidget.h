// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      coregui/Views/Components/OutputDataWidgets/OutputDataWidget.h
//! @brief     Defines class OutputDataWidget
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef OUTPUTDATAWIDGET_H
#define OUTPUTDATAWIDGET_H

#include <QWidget>
#include "NIntensityDataItem.h"

class PlotWidget;
class OutputDataToolBar;
class ProjectManager;
class IntensityDataPropertyWidget;
class QVBoxLayout;
class QHBoxLayout;

class BA_CORE_API_ OutputDataWidget : public QWidget
{
    Q_OBJECT
public:
    explicit OutputDataWidget(QWidget *parent = 0, bool isCreateToolBar = false, bool isCreatePropertyWidget = false, bool isProjections = false);

    void setCurrentItem(NIntensityDataItem *item);
    void setProjectManager(ProjectManager *projectManager);

public slots:

    void resetTriggered();
    void togglePropertyPanel();
    void savePlot();
    void toggleProjections();
    void projectionsChanged(bool projection);
    void setPropertyPanelVisible(bool visible);

private:
    PlotWidget *m_plotWidget;
    ProjectManager *m_projectManager;
    IntensityDataPropertyWidget *m_propertyWidget;
    OutputDataToolBar *m_toolBar;
    NIntensityDataItem *m_currentOutputDataItem;
    QVBoxLayout *m_mainLayout;
    QHBoxLayout *m_layout;

    bool m_isProjectionsVisible;
    void connectToobarSignals();
};




#endif

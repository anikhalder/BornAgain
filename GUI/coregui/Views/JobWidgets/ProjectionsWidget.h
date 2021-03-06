// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/JobWidgets/ProjectionsWidget.h
//! @brief     Defines class ProjectionsWidget
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2018
//! @authors   Scientific Computing Group at MLZ (see CITATION, AUTHORS)
//
// ************************************************************************** //

#ifndef PROJECTIONSWIDGET_H
#define PROJECTIONSWIDGET_H

#include "SessionItemWidget.h"
#include "MaskEditorFlags.h"

class ProjectionsPlot;
class QTabWidget;

//! Holds tabs of vertical and horizontal projections, located at the bottom of ProjectionsEditor.

class BA_CORE_API_ ProjectionsWidget : public SessionItemWidget
{
    Q_OBJECT

public:
    enum ETabId {HORIZONTAL, VERTICAL};

    ProjectionsWidget(QWidget* parent = 0);
    void setItem(SessionItem* intensityItem);

signals:
    void changeActivityRequest(MaskEditorFlags::Activity value);

public slots:
    void onActivityModeChanged(MaskEditorFlags::Activity value);
    void onMarginsChanged(double left, double right);

private slots:
    void onTabChanged(int tab_index);

private:
    void setConnected(bool isConnected);

    ProjectionsPlot* m_xProjection;
    ProjectionsPlot* m_yProjection;
    QTabWidget* m_tabWidget;
};

#endif // PROJECTIONSWIDGET_H

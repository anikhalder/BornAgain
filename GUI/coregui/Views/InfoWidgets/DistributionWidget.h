// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      coregui/Views/InfoWidgets/DistributionWidget.h
//! @brief     Defines class DistributionWidget
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2015
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   C. Durniak, M. Ganeva, G. Pospelov, W. Van Herck, J. Wuttke
//
// ************************************************************************** //

#ifndef DISTRIBUTIONWIDGET_H
#define DISTRIBUTIONWIDGET_H

#include <QWidget>
#include "WarningSignWidget.h"

class ParameterizedItem;
class AwesomePropertyEditor;
class QLabel;
class QCustomPlot;
class DistributionItem;
class QCPRange;
class QAction;

//! The DistributionWidget class plots 1d functions corresponding to domain's Distribution1D
class DistributionWidget : public QWidget
{
    Q_OBJECT

public:
    DistributionWidget(QWidget *parent = 0);
    virtual ~DistributionWidget() {}
    void setItem(DistributionItem *item);
    void plotItem();
    double getWidthOfBars(double min, double max, int samples);
    void setVerticalDashedLine(double xMin, double yMin, double xMax, double yMax);
    int getMaxYPosition(int y);
    void setXAxisName(QString xAxisName);
    QPoint getPositionForWarningSign();
    QString generateCodeSnippet();

public slots:
    void onMouseMove(QMouseEvent *event);
    void onMousePress(QMouseEvent *event);

protected:
    void resizeEvent(QResizeEvent *event);
private slots:
    void onPropertyChanged();   
    void resetView();

private:
    QCustomPlot *m_plot;
    DistributionItem *m_item;
    QLabel *m_label;
    QAction *m_resetAction;
    QCPRange *m_xRange;
    QCPRange *m_yRange;
    WarningSignWidget *m_warningSign;
};

#endif

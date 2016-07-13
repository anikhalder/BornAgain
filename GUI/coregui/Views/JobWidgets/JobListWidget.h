// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/JobWidgets/JobListWidget.h
//! @brief     Declares class JobListWidget
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#ifndef JOBLISTWIDGET_H
#define JOBLISTWIDGET_H

#include "WinDllMacros.h"
#include <QWidget>
#include <QModelIndexList>

class JobModel;
class JobListViewDelegate;
class QItemSelectionModel;
class ItemSelectorWidget;
class QModelIndex;

//! The JobListWidget class contains list view to select job items.

class BA_CORE_API_ JobListWidget : public QWidget
{
    Q_OBJECT
public:
    explicit JobListWidget(QWidget *parent = 0);

    void setModel(JobModel *model);

//    QSize sizeHint() const { return QSize(64, 768); }
//    QSize minimumSizeHint() const { return QSize(64, 64); }

    QItemSelectionModel *selectionModel();

signals:
    void contextMenuRequest(const QPoint &point, const QModelIndex &index);
    void selectionChanged(class JobItem *);

public slots:
    void makeJobItemSelected(class JobItem *jobItem);

private slots:
    void onItemSelectionChanged(class SessionItem *item);

private:
    JobListViewDelegate *m_listViewDelegate;
    ItemSelectorWidget *m_listView;
    JobModel *m_jobModel;
};

#endif // JOBLISTWIDGET_H

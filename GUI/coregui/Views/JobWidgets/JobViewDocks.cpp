// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/JobWidgets/JobViewDocks.cpp
//! @brief     Implements class JobViewDocks
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#include "JobViewDocks.h"
#include "JobView.h"
#include "JobModel.h"
#include "JobSelectorWidget.h"
#include "JobOutputDataWidget.h"
#include "JobRealTimeWidget.h"
#include "FitActivityPanel.h"
#include "JobMessagePanel.h"
#include "JobViewActivities.h"
#include <QAbstractItemView>
#include <QDockWidget>

namespace {
const JobViewFlags::Activity default_activity = JobViewFlags::JOB_VIEW_ACTIVITY;
}

JobViewDocks::JobViewDocks(JobView *parent)
    : QObject(parent)
    , m_jobSelector(0)
    , m_jobOutputDataWidget(0)
    , m_jobRealTimeWidget(0)
    , m_fitActivityPanel(0)
    , m_jobView(parent)
{

}

void JobViewDocks::initViews(class JobModel *jobModel)
{
    initJobWidgets(jobModel);
    initDocks();
}

//! Sets docks visibility so they match the activity flag.

void JobViewDocks::setActivity(int activity)
{
    QVector<JobViewFlags::Dock> docksToShow
            = JobViewActivities::activeDocks(JobViewFlags::Activity(activity));

    for (int i = 0; i < JobViewFlags::NUMBER_OF_DOCKS; i++) {
        JobViewFlags::Dock id = (JobViewFlags::Dock)i;
        if(docksToShow.contains(id)) {
            m_dockWidgets[id]->show();
        } else {
            m_dockWidgets[id]->hide();
        }
    }
}

void JobViewDocks::setItem(JobItem *jobItem)
{
    qDebug()  << "AAAA" << m_dockWidgets[JobViewFlags::FIT_PANEL_DOCK]->isHidden();
    jobOutputDataWidget()->setItem(jobItem);
    jobRealTimeWidget()->setItem(jobItem);
    fitActivityPanel()->setItem(jobItem);
}

//! Sets the state of JobView to the default.

void JobViewDocks::onResetLayout()
{
    m_jobView->setTrackingEnabled(false);
    QList<QDockWidget *> dockWidgetList = m_jobView->dockWidgets();
    foreach (QDockWidget *dockWidget, dockWidgetList) {
        dockWidget->setFloating(false);
        m_jobView->removeDockWidget(dockWidget);
    }

    m_jobView->addDockWidget(Qt::LeftDockWidgetArea, dock(JobViewFlags::JOB_LIST_DOCK));
    m_jobView->addDockWidget(Qt::RightDockWidgetArea, dock(JobViewFlags::REAL_TIME_DOCK));
    m_jobView->addDockWidget(Qt::RightDockWidgetArea, dock(JobViewFlags::FIT_PANEL_DOCK));
    m_jobView->addDockWidget(Qt::BottomDockWidgetArea, dock(JobViewFlags::JOB_MESSAGE_DOCK));

    foreach (QDockWidget *dockWidget, dockWidgetList)
        dockWidget->show();

    m_jobView->setTrackingEnabled(true);

    setActivity(default_activity);
}

//! Shows/hides JobSelectorWidget.

void JobViewDocks::onToggleJobSelector()
{
    QDockWidget *selectorDock = dock(JobViewFlags::JOB_LIST_DOCK);
    selectorDock->setHidden(!selectorDock->isHidden());
}

//! Returns job widget with given Id.

QWidget *JobViewDocks::jobWidget(JobViewFlags::Dock dockId)
{
    Q_ASSERT(dockId >=0 && dockId<m_jobWidgets.size());
    return m_jobWidgets[dockId];
}

//! Returns dock with given id.

QDockWidget *JobViewDocks::dock(JobViewFlags::Dock dockId)
{
    Q_ASSERT(dockId >=0 && dockId<m_dockWidgets.size());
    return m_dockWidgets[dockId];
}

QWidget *JobViewDocks::centralWidget()
{
    return m_jobOutputDataWidget;
}

//! Inits all main JobWidgets.

void JobViewDocks::initJobWidgets(JobModel *jobModel)
{
    m_jobWidgets.resize(JobViewFlags::NUMBER_OF_DOCKS);
    m_dockWidgets.resize(JobViewFlags::NUMBER_OF_DOCKS);

    m_jobOutputDataWidget = new JobOutputDataWidget(jobModel, m_jobView);

    m_jobSelector = new JobSelectorWidget(jobModel, m_jobView);
    m_jobWidgets[JobViewFlags::JOB_LIST_DOCK] = m_jobSelector;

    m_jobRealTimeWidget = new JobRealTimeWidget(jobModel, m_jobView);
    m_jobWidgets[JobViewFlags::REAL_TIME_DOCK] = m_jobRealTimeWidget;

    m_fitActivityPanel = new FitActivityPanel(jobModel, m_jobView);
    m_fitActivityPanel->setRealTimeWidget(m_jobRealTimeWidget);
    m_jobWidgets[JobViewFlags::FIT_PANEL_DOCK] = m_fitActivityPanel;

    m_jobWidgets[JobViewFlags::JOB_MESSAGE_DOCK] = new JobMessagePanel(m_jobView);

    m_jobView->setCentralWidget(centralWidget());
}

//! Init docks for JobView.

void JobViewDocks::initDocks()
{
    m_jobView->setDocumentMode(true);
    m_jobView->setTabPosition(Qt::AllDockWidgetAreas, QTabWidget::South);
    m_jobView->setCorner(Qt::BottomLeftCorner, Qt::LeftDockWidgetArea);
    m_jobView->setCorner(Qt::BottomRightCorner, Qt::RightDockWidgetArea);

    for (int i = 0; i < JobViewFlags::NUMBER_OF_DOCKS; i++) {
        QWidget *subWindow = jobWidget(JobViewFlags::Dock(i));
        m_dockWidgets[i] = m_jobView->addDockForWidget(subWindow);

        // Since we have 1-pixel splitters, we generally want to remove
        // frames around item views. So we apply this hack for now.
//        QList<QAbstractItemView*> frames =
//                subWindow->findChildren<QAbstractItemView*>();
//        for (int i = 0 ; i< frames.count(); ++i)
//            frames[i]->setFrameStyle(QFrame::NoFrame);

    }

    onResetLayout();
}
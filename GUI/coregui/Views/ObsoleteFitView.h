// ************************************************************************** //
//
//  BornAgain: simulate and fit scattering at grazing incidence
//
//! @file      GUI/coregui/Views/ObsoleteFitView.h
//! @brief     Declares class ObsoleteFitView
//!
//! @homepage  http://www.bornagainproject.org
//! @license   GNU General Public License v3 or higher (see COPYING)
//! @copyright Forschungszentrum Jülich GmbH 2016
//! @authors   Scientific Computing Group at MLZ Garching
//! @authors   Céline Durniak, Marina Ganeva, David Li, Gennady Pospelov
//! @authors   Walter Van Herck, Joachim Wuttke
//
// ************************************************************************** //

#ifndef OBSOLETEFITVIEW_H
#define OBSOLETEFITVIEW_H

#include <WinDllMacros.h>
#include <QWidget>

class MainWindow;
class QTabWidget;
class ObsoleteImportDataWidget;
class ObsoleteFitSettingsWidget;
class ObsoleteRunFitWidget;

class BA_CORE_API_ ObsoleteFitView : public QWidget
{
    Q_OBJECT

public:
    //! View containing tabs for fitting
    ObsoleteFitView(MainWindow *window);

private:
    QTabWidget *m_tabs;
    ObsoleteImportDataWidget *m_importDataWidget;
    ObsoleteFitSettingsWidget *m_fitSettingsWidget;
    ObsoleteRunFitWidget *m_runFitWidget;

};

#endif
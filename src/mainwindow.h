/**
 * \file mainwindow.h
 * \brief the main class controlling simulations and the main window
 * \author Sam Macpherson
 *
 * Copyright 2013  Sam Macpherson <sam.mack91@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/QThread>
#include <QtCore/QFile>

#include <QtWidgets/QMainWindow>

#include "ui_mainwindow.h"

#include "PluginManager.h"
#include "AVRProcessor.h"

/**
 * \brief the main class controlling simulations and the main window
 */
class MainWindow : public QMainWindow {

  Q_OBJECT

  public:
    MainWindow( QWidget* parent = 0 );
    ~MainWindow();


  public slots:

    /**
     * \brief a simple slot to load firmware using a file dialog
     */
    void loadFirmware(void);

  /**
   * \brief stops execution before reloading firmware and restarting execution
   */
    void reloadFirmware(void);

    /**
     * \brief starts execution of the simulation engine
     */
    void startSimulation(void);

    /**
     * \brief stops execution of the simulation engine
     */
    void stopSimulation(void);

    /**
     * \brief presents a dialog about the \em {Embedded System Simulator}
     */
    void aboutESS(void);

    /**
     * \brief toggle a plugin from an QAction event
     *
     * \param show a boolean indicating whether the plugin should be shown
     */
    void togglePlugin( bool show );

    /**
     * \brief protected timer event handler used to monitor log file
     *
     * \param e the timer event instance
     */
    void timerEvent(QTimerEvent * e);

  private:

    void initLogMonitor(void);

    void initSettings(void);
    void initComponents(void);

    void connectActions();

    Ui::MainWindow *ui;

    QString filename;

    AVRProcessor* cpu;
    QThread* cpuThread;
    PluginManager* pluginManager;

    QFile* log;
};

#endif // MAINWINDOW_H

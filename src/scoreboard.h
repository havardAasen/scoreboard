/*
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (C) 2023 Håvard F. Aasen <havard.f.aasen@pfft.no>
 */

#ifndef SCOREBOARD_H
#define SCOREBOARD_H

#include <QMainWindow>

#include "control_dialog.h"
#include "models/scoreboardModel.h"
#include "settings.h"
#include "timer.h"


namespace Ui {
    class Scoreboard;
}

class Scoreboard : public QMainWindow {
Q_OBJECT

public:
    explicit Scoreboard(QWidget *parent = nullptr);
    ~Scoreboard() override;

private slots:
    void updateClock();
    void updateHomeScore(int score);
    void updateGuestScore(int score);
    void updateRoundNumber(int round);
    void updateRoundTimer();
    void toggleRound();
    void roundDone();
    void resetScoreboard();
    void controlDialog();
    [[maybe_unused]] void about();
    [[maybe_unused]] static void aboutQt();
    [[maybe_unused]] void settingsDialog();

signals:
    void matchTimeChanged(int time);

private:
    Ui::Scoreboard *ui;
    ControlDialog *m_controlDialog{};
    Timer *m_round{};
    Settings *m_settings{};

    void loadStylesheet(const char *file);
    void changeFontSize(int size);
    void toggleFullscreen();
    void startRound();
    void stopRound();
    static void delay(int milliseconds);
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void closeEvent(QCloseEvent *event) override;
};

#endif // SCOREBOARD_H

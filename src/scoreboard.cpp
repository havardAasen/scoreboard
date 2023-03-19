/*
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (C) 2023 Håvard F. Aasen <havard.f.aasen@pfft.no>
 */

#include <QFile>
#include <QMessageBox>
#include <QMouseEvent>
#include <QTime>

#include "about_dialog.h"
#include "scoreboard.h"
#include "settings_dialog.h"
#include "ui_scoreboard.h"


Scoreboard::Scoreboard(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::Scoreboard)
{
    ui->setupUi(this);
    m_settings = new Settings();

    auto clockTicker = new QTimer(this);
    connect(clockTicker, &QTimer::timeout, this, &Scoreboard::updateClock);
    clockTicker->start(1000);

    loadStylesheet(":/stylesheets/stylesheet.qss");

    controlDialog();
    resetScoreboard();
}

Scoreboard::~Scoreboard()
{
    delete m_round;
    delete m_settings;
    delete ui;
}

void Scoreboard::loadStylesheet(const char *file)
{
    QFile fileStyle(file);
    if (fileStyle.open(QIODevice::ReadOnly | QIODevice::Text)) {
        this->setStyleSheet(QLatin1String(fileStyle.readAll()));
        this->ensurePolished();
        fileStyle.close();
    } else {
        qWarning("Could not load stylesheet: '%s'.\n", file);
    }
}

void Scoreboard::controlDialog()
{
    if (!m_controlDialog) {
        m_controlDialog = new ControlDialog(this);

        auto *scoreboardModel = new ScoreboardModel(this);
        m_controlDialog->setModel(*scoreboardModel);
        connect(scoreboardModel, &ScoreboardModel::homeScoreChanged, this,
                &Scoreboard::updateHomeScore);
        connect(scoreboardModel, &ScoreboardModel::guestScoreChanged, this,
                &Scoreboard::updateGuestScore);
        connect(scoreboardModel, &ScoreboardModel::roundNumberChanged, this,
                &Scoreboard::updateRoundNumber);
        connect(this, &Scoreboard::matchTimeChanged, m_controlDialog,
                &ControlDialog::updateMatchTime);
        connect(m_controlDialog, &ControlDialog::startStop, this, &Scoreboard::toggleRound);
        connect(m_controlDialog, &ControlDialog::resetGame, this, &Scoreboard::resetScoreboard);
    }
    m_controlDialog->show();
    m_controlDialog->raise();
    m_controlDialog->activateWindow();
}

[[maybe_unused]] void Scoreboard::settingsDialog()
{
    auto dialog = new SettingsDialog(m_settings, this);
    if (dialog->exec() == QDialog::Accepted)
        changeFontSize(m_settings->fontSize());
}

void Scoreboard::roundDone()
{
    int milliseconds = 100;
    for (int i = 0; i < 5; i++) {
        this->setStyleSheet("QMainWindow { background-color: red }");
        delay(milliseconds);
        this->setStyleSheet("QMainWindow { background-color: black }");
        delay(milliseconds);
    }
}

void Scoreboard::delay(const int milliseconds)
{
    auto dieTime = QTime::currentTime().addMSecs(milliseconds);
    while (QTime::currentTime() < dieTime)
        QApplication::processEvents(QEventLoop::AllEvents, 100);
}

void Scoreboard::updateHomeScore(const int score)
{
    ui->homeScoreLabel->setNum(score);
}

void Scoreboard::updateGuestScore(const int score)
{
    ui->guestScoreLabel->setNum(score);
}

void Scoreboard::updateRoundNumber(const int round)
{
    ui->roundLabel->setNum(round);
}

void Scoreboard::updateRoundTimer()
{
    ui->timerLabel->setText(QTime(0, 0).addSecs(m_round->timeElapsed()).toString("mm:ss"));
}

[[maybe_unused]] void Scoreboard::about()
{
    auto dialog = new AboutDialog(this);
    dialog->show();
}

[[maybe_unused]] void Scoreboard::aboutQt()
{
    QApplication::aboutQt();
}

void Scoreboard::updateClock()
{
    auto currentTime = QTime::currentTime();
    auto text = currentTime.toString("hh:mm");
    if ((currentTime.second() % 2) == 0)
        text[2] = ' ';
    ui->clockLabel->setText(text);
}

void Scoreboard::changeFontSize(const int size)
{
    QString str = "font: ";
    str.append(QString::number(size));
    str.append("pt");

    ui->clockLabel->setStyleSheet(str);
    ui->timerLabel->setStyleSheet(str);
    ui->homeScoreLabel->setStyleSheet(str);
    ui->homeLabel->setStyleSheet(str);
    ui->guestScoreLabel->setStyleSheet(str);
    ui->guestLabel->setStyleSheet(str);
    ui->roundLabel->setStyleSheet(str);
}

void Scoreboard::toggleFullscreen()
{
    if (this->windowState() == Qt::WindowFullScreen) {
        this->setWindowState(Qt::WindowNoState);
        ui->menuBar->setVisible(true);
    } else {
        this->setWindowState(Qt::WindowFullScreen);
        ui->menuBar->setVisible(false);
    }
}

void Scoreboard::toggleRound()
{
    m_round->isActive() ? stopRound() : startRound();
}

void Scoreboard::startRound()
{
    m_round->start();
}

void Scoreboard::stopRound()
{
    m_round->stop();
}

void Scoreboard::resetScoreboard()
{
    ui->timerLabel->setText("00:00");
    m_round = new Timer(m_settings->matchTime());
    emit matchTimeChanged(m_settings->matchTime());
    connect(m_round, &Timer::timerElapsed, this, &Scoreboard::roundDone);
    connect(m_round, &Timer::timerTick, this, &Scoreboard::updateRoundTimer);
}

void Scoreboard::mouseDoubleClickEvent(QMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton)
        toggleFullscreen();
}

void Scoreboard::closeEvent(QCloseEvent *event)
{
    int ret = QMessageBox::warning(this, tr("Confirm Exit"),
                                   tr("Are you sure you want to exit?"),
                                   QMessageBox::Close | QMessageBox::Cancel,
                                   QMessageBox::Cancel);
    switch (ret) {
        case QMessageBox::Close:
            event->accept();
            break;
        case QMessageBox::Cancel:
        default:
            event->ignore();
    }
}

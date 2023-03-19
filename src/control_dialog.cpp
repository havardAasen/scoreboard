/*
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (C) 2023 Håvard F. Aasen <havard.f.aasen@pfft.no>
 */

#include <QMessageBox>
#include <QTime>

#include "control_dialog.h"
#include "ui_control_dialog.h"

ControlDialog::ControlDialog(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::ControlDialog)
{
    ui->setupUi(this);

    connect(ui->startStopBtn, &QPushButton::clicked, this, &ControlDialog::startStop);
}

ControlDialog::~ControlDialog()
{
    delete ui;
}

void ControlDialog::setModel(ScoreboardModel &model)
{
    m_scoreboardModel = &model;
    connect(ui->homeScoreSpinBox, &QSpinBox::valueChanged, m_scoreboardModel,
            &ScoreboardModel::updateHomeScore);
    connect(ui->guestScoreSpinBox, &QSpinBox::valueChanged, m_scoreboardModel,
            &ScoreboardModel::updateGuestScore);
    connect(ui->roundSpinbox, &QSpinBox::valueChanged, m_scoreboardModel,
            &ScoreboardModel::updateRoundNumber);
}

void ControlDialog::updateMatchTime(int time)
{
    ui->matchTime->setTime(QTime(0, 0).addSecs(time));
}

[[maybe_unused]] void ControlDialog::resetTime()
{
    int ret = QMessageBox::warning(this, tr("Reset timer"),
                                   tr("Are you sure want to reset timer?"),
                                   QMessageBox::Ok | QMessageBox::Cancel,
                                   QMessageBox::Cancel);
    if (ret == QMessageBox::Ok)
        emit resetGame();
}

/*
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (C) 2023 Håvard F. Aasen <havard.f.aasen@pfft.no>
 */

#include "settings_dialog.h"
#include "ui_settings_dialog.h"

SettingsDialog::SettingsDialog(Settings *settings, QWidget *parent) :
        QDialog(parent),
        ui(new Ui::SettingsDialog),
        m_settings(settings)
{
    ui->setupUi(this);

    ui->matchTime->setTime(QTime(0, 0).addSecs(m_settings->matchTime()));
    ui->breakTime->setTime(QTime(0, 0).addSecs(m_settings->breakTime()));
    ui->fontSizeSpinbox->setValue(m_settings->fontSize());
}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::accept()
{
    m_settings->matchTime(QTime(0, 0).secsTo(ui->matchTime->time()));
    m_settings->breakTime(QTime(0, 0).secsTo(ui->breakTime->time()));
    m_settings->fontSize(ui->fontSizeSpinbox->value());

    qDebug() << "Settings is saved.";
    QDialog::done(QDialog::Accepted);
}

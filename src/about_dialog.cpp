/*
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (C) 2023 Håvard F. Aasen <havard.f.aasen@pfft.no>
 */

#include "about_dialog.h"
#include "version.h"
#include "ui_about_dialog.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    ui->labelVersion->setText(tr("**Scoreboard %1**").arg(VERSION_STRING));
}

AboutDialog::~AboutDialog()
{
    delete ui;
}

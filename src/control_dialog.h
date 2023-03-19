/*
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (C) 2023 Håvard F. Aasen <havard.f.aasen@pfft.no>
 */

#ifndef CONTROL_DIALOG_H
#define CONTROL_DIALOG_H

#include <QDialog>

#include "models/scoreboardModel.h"

namespace Ui {
    class ControlDialog;
}

class ControlDialog : public QDialog {
Q_OBJECT

public:
    explicit ControlDialog(QWidget *parent = nullptr);
    ~ControlDialog() override;

    void setModel(ScoreboardModel &model);

signals:
    void startStop();
    void resetGame();

public slots:
    void updateMatchTime(int time);

private slots:
    [[maybe_unused]] void resetTime();

private:
    Ui::ControlDialog *ui{};
    ScoreboardModel *m_scoreboardModel{};
};

#endif // CONTROL_DIALOG_H

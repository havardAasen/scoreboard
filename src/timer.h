/*
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (C) 2023 Håvard F. Aasen <havard.f.aasen@pfft.no>
 */

#ifndef TIMER_H
#define TIMER_H

#include <QObject>
#include <QTimer>

class Timer : public QObject {
Q_OBJECT

public:
    explicit Timer(int time);

    [[nodiscard]] bool isActive() const;
    [[nodiscard]] int timeElapsed() const;
    void start();
    void stop();

signals:
    void timerElapsed();
    void timerTick();

private slots:
    void updateTime();

private:
    QTimer *m_ticker{};
    int m_timeElapsed{};
    int m_origTime{};
};

#endif // TIMER_H

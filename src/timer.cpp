/*
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (C) 2023 Håvard F. Aasen <havard.f.aasen@pfft.no>
 */

#include "timer.h"

Timer::Timer(int time) :
        m_origTime(time)
{
    m_ticker = new QTimer(this);
    connect(m_ticker, &QTimer::timeout, this, &Timer::updateTime);
}

bool Timer::isActive() const
{
    return m_ticker->isActive();
}

void Timer::updateTime()
{
    m_timeElapsed++;
    emit timerTick();

    if (m_timeElapsed >= m_origTime) {
        stop();
        emit timerElapsed();
    }
}

void Timer::start()
{
    m_ticker->start(1000);
}

void Timer::stop()
{
    m_ticker->stop();
}

int Timer::timeElapsed() const
{
    return m_timeElapsed;
}

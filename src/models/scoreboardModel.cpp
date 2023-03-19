/*
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (C) 2023 Håvard F. Aasen <havard.f.aasen@pfft.no>
 */

#include "scoreboardModel.h"

ScoreboardModel::ScoreboardModel(QObject *parent) : QObject(parent)
{}

void ScoreboardModel::updateHomeScore(const int newScore)
{
    if (m_homeScore == newScore)
        return;
    m_homeScore = newScore;
    emit homeScoreChanged(m_homeScore);
}

void ScoreboardModel::updateGuestScore(const int newScore)
{
    if (m_guestScore == newScore)
        return;
    m_guestScore = newScore;
    emit guestScoreChanged(m_guestScore);
}

void ScoreboardModel::updateRoundNumber(const int newRound)
{
    if (m_roundNumber == newRound)
        return;
    m_roundNumber = newRound;
    emit roundNumberChanged(m_roundNumber);
}

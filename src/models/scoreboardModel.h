/*
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (C) 2023 Håvard F. Aasen <havard.f.aasen@pfft.no>
 */

#ifndef SCOREBOARD_MODEL_H
#define SCOREBOARD_MODEL_H

#include <QObject>

class ScoreboardModel : public QObject {
Q_OBJECT

public:
    explicit ScoreboardModel(QObject *parent = nullptr);

public slots:
    void updateHomeScore(int newScore);
    void updateGuestScore(int newScore);
    void updateRoundNumber(int newRound);

signals:
    void homeScoreChanged(int score);
    void guestScoreChanged(int score);
    void roundNumberChanged(int round);

private:
    int m_homeScore{};
    int m_guestScore{};
    int m_roundNumber{};
};

#endif // SCOREBOARD_MODEL_H

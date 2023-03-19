/*
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (C) 2023 Håvard F. Aasen <havard.f.aasen@pfft.no>
 */

#include <QDebug>
#include <QSettings>

#include "settings.h"

/* Default settings. */
constexpr int c_matchTime = 900;
constexpr int c_breakTime = 300;
constexpr int c_fontSize = 16;

Settings::Settings()
{
    loadSettings();
}

Settings::~Settings()
{
    saveSettings();
}

bool Settings::matchTime(const int time)
{
    if (m_matchTime == time)
        return false;
    m_matchTime = time;
    qDebug("New match time: %d seconds.", time);
    return true;
}

bool Settings::breakTime(const int time)
{
    if (m_breakTime == time)
        return false;
    m_breakTime = time;
    qDebug("New break time: %d seconds.", time);
    return true;
}

bool Settings::fontSize(const int size)
{
    if (m_fontSize == size)
        return false;
    m_fontSize = size;
    qDebug("New font size: %d.", size);
    return true;
}

int Settings::matchTime() const
{
    return m_matchTime;
}

int Settings::breakTime() const
{
    return m_breakTime;
}

int Settings::fontSize() const
{
    return m_fontSize;
}

void Settings::loadSettings()
{
    QSettings::setDefaultFormat(QSettings::IniFormat);
    QSettings settings;
    m_matchTime = settings.value("matchTime", c_matchTime).toInt();
    m_breakTime = settings.value("breakTime", c_breakTime).toInt();
    m_fontSize = settings.value("fontSize", c_fontSize).toInt();

    qDebug("Settings is loaded from [%s]", settings.fileName().toStdString().c_str());
}

void Settings::saveSettings() const
{
    QSettings::setDefaultFormat(QSettings::IniFormat);
    QSettings settings;
    settings.setValue("matchTime", m_matchTime);
    settings.setValue("breakTime", m_breakTime);
    settings.setValue("fontSize", m_fontSize);

    qDebug("Settings is saved to [%s]", settings.fileName().toStdString().c_str());
}

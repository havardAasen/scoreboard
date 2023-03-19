/*
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (C) 2023 Håvard F. Aasen <havard.f.aasen@pfft.no>
 */

#ifndef SETTINGS_H
#define SETTINGS_H


class Settings {
public:
    Settings();
    ~Settings();

    /**
     * Set new match time.
     * @param time in seconds.
     * @return @c true if new time is different from old, @c false if new time is identical with old.
     */
    bool matchTime(int time);

    /**
     * Set new break time.
     * @param time in seconds.
     * @return @c true if new time is different from old, @c false if new time is identical with old.
     */
    bool breakTime(int time);

    /**
     * Set new font size
     * @param size
     * @return @c true if new size is different from old, @c false if new size is identical with old.
     */
    bool fontSize(int size);

    [[nodiscard]] int matchTime() const;
    [[nodiscard]] int breakTime() const;
    [[nodiscard]] int fontSize() const;

private:
    int m_matchTime{};
    int m_breakTime{};
    int m_fontSize{};

    /**
     * @brief Load application settings from file.
     *
     * The file is in INI format, so it is identical on all platforms.
     */
    void loadSettings();

    /**
     * @brief Save application settings to file.
     *
     * The file is saved in INI format, so it is identical on all platforms.
     */
    void saveSettings() const;
};

#endif // SETTINGS_H

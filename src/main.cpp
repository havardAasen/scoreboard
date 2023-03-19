/*
 * SPDX-License-Identifier: Apache-2.0
 * Copyright (C) 2023 Håvard F. Aasen <havard.f.aasen@pfft.no>
 */

#include <QApplication>

#include "scoreboard.h"
#include "version.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QApplication::setOrganizationName("gsi");
    QApplication::setApplicationName("scoreboard");

    qDebug("App data: Version: %s, Build date: %s", VERSION_STRING, BUILD_DATE);

    Scoreboard scoreBoard;
    scoreBoard.show();
    return QApplication::exec();
}

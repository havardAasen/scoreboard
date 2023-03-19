cmake_minimum_required(VERSION 3.14)

file(READ src/version.h version)
string(REGEX MATCH "VERSION_MAJOR ([0-9]*)" _ ${version})
set(SCOREBOARD_VERSION_MAJOR ${CMAKE_MATCH_1})
string(REGEX MATCH "VERSION_MINOR ([0-9]*)" _ ${version})
set(SCOREBOARD_VERSION_MINOR ${CMAKE_MATCH_1})
string(REGEX MATCH "VERSION_PATCH ([0-9]*)" _ ${version})
set(SCOREBOARD_VERSION_PATCH ${CMAKE_MATCH_1})
string(REGEX MATCH "VERSION_STRING \"([-0-9A-Za-z.]*)" _ ${version})
set(SCOREBOARD_VERSION_STRING ${CMAKE_MATCH_1})

message("Configuring scoreboard for version: ${SCOREBOARD_VERSION_STRING}\n")

project(scoreboard
        LANGUAGES CXX
        HOMEPAGE_URL "https://github.com/havardAasen/scoreboard"
        DESCRIPTION "Keeping track of time and goals in matches"
        VERSION "${SCOREBOARD_VERSION_MAJOR}.${SCOREBOARD_VERSION_MINOR}.${SCOREBOARD_VERSION_PATCH}"
        )

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")
include(GNUInstallDirs)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if (MSVC)
    add_compile_options(/W4)
else ()
    add_compile_options(-Wall -Wextra)
endif ()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS
        Core
        Gui
        Widgets
        )
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS
        Core
        Gui
        Widgets
        )

add_subdirectory(src)

include(packaging)

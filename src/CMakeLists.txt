set(SOURCES
        ../resources/resources.qrc
        about_dialog.cpp
        about_dialog.ui
        control_dialog.cpp
        control_dialog.ui
        main.cpp
        models/scoreboardModel.cpp
        settings.cpp
        scoreboard.cpp
        scoreboard.ui
        settings_dialog.cpp
        settings_dialog.ui
        timer.cpp
        )

if (${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(scoreboard
            MANUAL_FINALIZATION
            ${SOURCES}
            )
else ()
    add_executable(scoreboard
            ${SOURCES}
            )
endif ()

target_link_libraries(scoreboard PRIVATE
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

set_target_properties(scoreboard PROPERTIES
        WIN32_EXECUTABLE TRUE
        MACOSX_BUNDLE TRUE
        )

install(TARGETS scoreboard
        BUNDLE DESTINATION .
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        )

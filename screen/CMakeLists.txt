set(SOURCES
    button.h button.cpp
    inputhandler.h inputhandler.cpp
    screen.h screen.cpp
    ScreenManagerRemoteControl.h
    uipanel.h uipanel.cpp
)

add_library(screen ${SOURCES})

target_include_directories(screen PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(screen PUBLIC sfml-graphics sfml-window sfml-system utils)

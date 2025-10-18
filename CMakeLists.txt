cmake_minimum_required(VERSION 3.16)

project(FnafMinigames LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
    sfml
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG        2.6.2
)

set(SFML_FETCH_DEPENDENCIES TRUE)

FetchContent_MakeAvailable(sfml)

add_executable(FnafMinigames main.cpp
    button.h button.cpp
    engine.h engine.cpp
    inputhandler.h inputhandler.cpp
    screen.h screen.cpp
    screenmanager.h screenmanager.cpp
    ScreenManagerRemoteControl.h
    selectinputhandler.h selectinputhandler.cpp
    selectscreen.h selectscreen.cpp
    selectuipanel.h selectuipanel.cpp
    shadermanager.h shadermanager.cpp
    uipanel.h uipanel.cpp
)

target_link_libraries(FnafMinigames PRIVATE sfml-graphics sfml-window sfml-system)

include(GNUInstallDirs)
install(TARGETS FnafMinigames
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

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

add_subdirectory(engine)
add_subdirectory(screen)
add_subdirectory(menu)
add_subdirectory(utils)

add_executable(FnafMinigames main.cpp)

target_link_libraries(FnafMinigames PRIVATE sfml-graphics sfml-window sfml-system engine screen menu utils)

include(GNUInstallDirs)
install(TARGETS FnafMinigames
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

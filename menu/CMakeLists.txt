set(SOURCES
    mainmenuinputhandler.h mainmenuinputhandler.cpp
    mainmenuscreen.h mainmenuscreen.cpp
    mainmenuuipanel.h mainmenuuipanel.cpp
)

add_library(menu ${SOURCES}
    fnaf2menuscreen.h fnaf2menuscreen.cpp
    fnaf2menuuipanel.h fnaf2menuuipanel.cpp
    fnaf2menuinputhandler.h fnaf2menuinputhandler.cpp)

target_include_directories(menu PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(menu PUBLIC sfml-graphics sfml-window sfml-system screen utils)

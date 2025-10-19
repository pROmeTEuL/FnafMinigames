set(SOURCES
    selectinputhandler.h selectinputhandler.cpp
    selectscreen.h selectscreen.cpp
    selectuipanel.h selectuipanel.cpp
)

add_library(select ${SOURCES})

target_include_directories(select PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(select PUBLIC sfml-graphics sfml-window sfml-system screen utils)

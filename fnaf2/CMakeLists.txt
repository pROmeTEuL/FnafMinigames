set(SOURCES
    gogogoscreen.h gogogoscreen.cpp
)

add_library(fnaf2 ${SOURCES})

target_include_directories(fnaf2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(fnaf2 PUBLIC sfml-graphics sfml-window sfml-system screen utils)

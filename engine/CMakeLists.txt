add_library(engine
    engine.h engine.cpp
    screenmanager.h screenmanager.cpp
)

target_include_directories(engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(engine PUBLIC sfml-graphics sfml-window sfml-system screen menu fnaf2 utils)

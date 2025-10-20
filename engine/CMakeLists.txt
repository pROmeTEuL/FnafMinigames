set(SOURCES
    	engine.h engine.cpp
	screenmanager.h screenmanager.cpp
)

add_library(engine ${SOURCES})

target_include_directories(engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(engine PUBLIC sfml-graphics sfml-window sfml-system screen menu utils)

set(SOURCES
	shadermanager.h shadermanager.cpp
)

add_library(utils ${SOURCES})

target_include_directories(utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(utils PUBLIC sfml-graphics sfml-window sfml-system)

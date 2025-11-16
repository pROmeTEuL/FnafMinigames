add_library(utils
    shadermanager.h shadermanager.cpp
    player.h player.cpp
    texturemanager.h texturemanager.cpp
    collidable.h collidable.cpp
    border.cpp border.h


)

target_include_directories(utils PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(utils PUBLIC sfml-graphics sfml-window sfml-system)

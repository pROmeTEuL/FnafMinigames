add_library(fnaf2
    takecaketochildrenscreen.h takecaketochildrenscreen.cpp
    takecaketochildreninputhandler.h takecaketochildreninputhandler.cpp
    takecaketochildrenuipanel.h takecaketochildrenuipanel.cpp
    takecaketochildrenchild.cpp takecaketochildrenchild.h
)

target_include_directories(fnaf2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(fnaf2 PUBLIC sfml-graphics sfml-window sfml-system screen utils)

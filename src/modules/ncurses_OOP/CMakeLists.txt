
set(PROJECT_NAME ncurses_oop_lib)


project(${PROJECT_NAME} VERSION ${VERSION_PROJECT} LANGUAGES ${LANGUAGES_PROJECT})


add_library(${PROJECT_NAME} SHARED
    Screen.cpp
    Window.cpp
    ../../../include/modules/ncurses_OOP/Screen.hpp
    ../../../include/modules/ncurses_OOP/Window.hpp
    ../../../include/modules/ncurses_OOP/Config.hpp
    ../../../include/modules/ncurses_OOP/Output.hpp
    ../../../include/modules/ncurses_OOP/InterfaceBasicBox.hpp
    ../../../include/modules/ncurses_OOP/CreateBasicBox.hpp
)


target_include_directories(${PROJECT_NAME} PUBLIC
    ../../../include/modules/ncurses_OOP/
)

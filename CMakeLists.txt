cmake_minimum_required(VERSION 3.28)

set(VERSION_PROJECT 0.1.5)
set(LANGUAGES_PROJECT CXX)

project(CarLudGine VERSION ${VERSION_PROJECT} LANGUAGES ${LANGUAGES_PROJECT})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

# NCURSES
set(CURSES_NEED_NCURSES ON)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
set(PD_OR_N_CURSES ${CURSES_LIBRARIES})



add_executable(CarLudGine
    src/main.cpp
)

add_subdirectory(src/modules/ncurses_OOP/)

target_link_libraries(CarLudGine PRIVATE ncurses_oop_lib
    ${PD_OR_N_CURSES}
)
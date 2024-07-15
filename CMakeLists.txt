cmake_minimum_required(VERSION 3.26)

project(CarLudGine)
set(CMAKE_CXX_STANDARD 20)

set(CURSES_NEED_NCURSES ON)
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
set(PD_OR_N_CURSES ${CURSES_LIBRARIES})

add_executable(CarLudGine
    src/main.cpp
)

target_link_libraries(CarLudGine
    ${PD_OR_N_CURSES}
)
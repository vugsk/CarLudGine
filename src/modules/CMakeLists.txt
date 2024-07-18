
set(PROJECT_NAME modules_lib)

project(${PROJECT_NAME} VERSION ${VERSION_PROJECT}
    LANGUAGES ${LANGUAGES_PROJECT})


#add_subdirectory(ncurses_OOP/)



add_library(${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} PUBLIC
    ncurses_oop_lib
)

#target_include_directories(${PROJECT_NAME}
#    PUBLIC ${PROJECT_SOURCE_DIR}/include
#)
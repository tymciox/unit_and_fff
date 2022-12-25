cmake_minimum_required(VERSION 3.23)

project(vbat C)


add_compile_options(-Wall -Wextra)

add_subdirectory(unity)

link_libraries(Unity)

set(INCLUDE_DIR
    src
)

include_directories(${INCLUDE_DIR})

add_executable(
    ${CMAKE_PROJECT_NAME}
    src/vbat.c
)

enable_testing()

add_test(test_nr_1 ${CMAKE_PROJECT_NAME})
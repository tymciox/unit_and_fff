cmake_minimum_required(VERSION 3.23)

project(vbat C)

add_compile_options(-Wall -Wextra)

add_subdirectory(test)

set(INCLUDE_DIR
    src
)

include_directories(${INCLUDE_DIR})

add_executable(
    ${CMAKE_PROJECT_NAME}
    src/vbat.c
)

target_link_libraries(
    ${CMAKE_PROJECT_NAME}
    Unity
)

enable_testing()

add_test(test_nr_1 ${CMAKE_PROJECT_NAME})
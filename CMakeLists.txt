cmake_minimum_required(VERSION 3.23)

project(vbat C)

add_compile_options(-Wall -Wextra)

add_subdirectory(test)

set(INCLUDE_DIR
    src
)

set(INCLUDE_FFF
    test/fff
)

include_directories(${INCLUDE_DIR} ${INCLUDE_FFF})

add_executable(
    ${CMAKE_PROJECT_NAME}
    src/vbat.c
    test/TestProductionCode_main.c
    test/TestProductionCode_Runner.c
    test/TestProductionCode.c
)

target_link_libraries(
    ${CMAKE_PROJECT_NAME}
    Unity
)

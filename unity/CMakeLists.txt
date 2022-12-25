cmake_minimum_required(VERSION 3.23)

add_library(Unity STATIC
    unity.c
)

target_include_directories(Unity PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)
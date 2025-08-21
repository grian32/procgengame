cmake_minimum_required(VERSION 4.0)
project(proc_gen_game C)

set(CMAKE_C_STANDARD 11)

find_package(raylib REQUIRED)

add_executable(proc_gen_game main.c)

target_link_libraries(proc_gen_game raylib)

if (UNIX)
    target_link_libraries(proc_gen_game m pthread dl)
endif()

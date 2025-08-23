cmake_minimum_required(VERSION 4.0)
project(proc_gen_game C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(OpenGL REQUIRED)

add_library(glad STATIC glad/src/glad.c)
target_include_directories(glad PUBLIC glad/include)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW REQUIRED glfw3)

add_executable(proc_gen_game main.cpp util.cpp util.h input.cpp input.h
        Shader.cpp
        Shader.h)
target_include_directories(proc_gen_game PRIVATE glad/include ${GLFW_INCLUDE_DIRs})

target_link_libraries(proc_gen_game OpenGL::GL glad ${GLFW_LIBRARIES} m)

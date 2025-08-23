cmake_minimum_required(VERSION 4.0)
project(proc_gen_game C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(OpenGL REQUIRED)

add_library(glad STATIC glad/src/glad.c)
target_include_directories(glad PUBLIC glad/include)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW REQUIRED glfw3)

add_executable(proc_gen_game main.c util.c util.h input.c input.h)
target_include_directories(proc_gen_game PRIVATE glad/include ${GLFW_INCLUDE_DIRs})

target_link_libraries(proc_gen_game OpenGL::GL glad ${GLFW_LIBRARIES} m)

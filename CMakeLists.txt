cmake_minimum_required(VERSION 3.29)
project(breakout)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

add_library(glad STATIC src/glad.c)
target_include_directories(glad PUBLIC include)

add_executable(main src/main.cpp)

target_link_libraries(main PRIVATE OpenGL::GL glfw glad)

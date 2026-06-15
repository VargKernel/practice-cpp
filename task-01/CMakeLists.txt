cmake_minimum_required(VERSION 3.0)

project(task-01)

add_executable(task-01 main.cpp)

install(TARGETS task-01 RUNTIME DESTINATION bin)

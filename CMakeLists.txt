cmake_minimum_required(VERSION 3.0)

project(log3 LANGUAGES C)

add_executable(log3 main.c)

install(TARGETS log3 RUNTIME DESTINATION bin)

cmake_minimum_required(VERSION 3.0)

project(log3 LANGUAGES CXX)

find_package(FMT)

add_executable(log3 main.cpp)
set_property(TARGET log3 PROPERTY CXX_STANDARD 17)
target_link_libraries(log3 fmt::fmt)

install(TARGETS log3 RUNTIME DESTINATION bin)

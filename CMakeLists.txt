cmake_minimum_required(VERSION 3.15)
project(Connection)

set(CMAKE_CXX_STANDARD 17)

if (WIN32)
    set(SFML_STATIC_LIBRARIES TRUE)
endif (WIN32)
set(CMAKE_BUILD_TYPE Debug)
find_package(SFML 2 COMPONENTS graphics system window audio network REQUIRED)
add_executable(Connection main.cpp)
target_link_libraries(Connection sfml-graphics sfml-system sfml-window sfml-audio sfml-network)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 11)

project(Snake)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})

add_executable(snake
    src/main.cpp
    src/Board.cpp
    src/Snake.cpp
    src/Pineapple.cpp
)

target_link_libraries(snake ${SDL2_LIBRARIES})
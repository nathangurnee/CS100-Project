cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 11)

ADD_SUBDIRECTORY(googletest)

project(Snake)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})

add_executable(snake
    src/main.cpp
    src/Board.cpp
    src/Snake.cpp
    src/Pineapple.cpp
    src/SnakeMovement.cpp
    src/PineappleMovement.cpp
    src/Image.cpp
)

add_executable(test
    src/Image.cpp
    src/Pineapple.cpp
    src/PineappleMovement.cpp
    tests/unit_test.cpp
)

target_link_libraries(snake ${SDL2_LIBRARIES})
target_link_libraries(test ${SDL2_LIBRARIES})
TARGET_LINK_LIBRARIES(test gtest)
TARGET_COMPILE_DEFINITIONS(test PRIVATE gtest_disable_pthreads=ON)
cmake_minimum_required(VERSION 3.5)
project(tic_tac_toe_improved)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCE_FILES
        main.cpp
        ./Player/*
        ./Board/*
        ./Manager/*
        ./utils/*
        )

add_executable(tic_tac_toe ${SOURCE_FILES})
target_link_libraries(tic_tac_toe ${CURSES_LIBRARIES})
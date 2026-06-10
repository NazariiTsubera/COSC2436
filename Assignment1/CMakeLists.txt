cmake_minimum_required(VERSION 4.2)
project(Assignment1)

set(CMAKE_CXX_STANDARD 26)

add_executable(Assignment1 src/main.cpp
        src/Vector.hpp
        src/Vector.h
        src/Program.hpp
        src/Program.h
        src/Commands.h
)

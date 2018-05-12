cmake_minimum_required(VERSION 3.8)
project(battledev)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall")

add_executable(dijkstra exemple_dijkstra.cpp)
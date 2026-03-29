cmake_minimum_required(VERSION 4.0.2)
project(HugeNumber LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(HugeNumber
    "HugeNumber.cpp"
)
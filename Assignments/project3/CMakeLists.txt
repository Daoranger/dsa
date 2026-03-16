cmake_minimum_required(VERSION 3.28)
project(LibraryManagement LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Catch2 3 REQUIRED)

add_executable(LibraryManager
        Book.cc
        User.cc
        main.cc
)

add_executable(LibraryTests
        test.cc
        Book.cc
)

target_link_libraries(LibraryTests PRIVATE Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(LibraryTests)
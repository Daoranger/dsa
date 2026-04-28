cmake_minimum_required(VERSION 4.0.2)
project(HugeNumber LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(Shapes
        "Shapes.cc"
        "main.cc"
)

add_executable(ShapesTest
        "Shapes.cc"
        "ShapesTest.cpp"
)

target_link_libraries(
        ShapesTest
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(ShapesTest)
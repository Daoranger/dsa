cmake_minimum_required(VERSION 3.14)
project(Project2)

# GoogleTest require at least C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG v1.17.0
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(XYPoint_test
        XYPoint.cc
        XYPoint_test.cc
)

target_link_libraries(XYPoint_test PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(XYPoint_test)
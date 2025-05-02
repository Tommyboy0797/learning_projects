# CMakeLists.txt — Windows x64 build
cmake_minimum_required(VERSION 3.20)
project(TOMMY LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the build type to Release for optimizations
set(CMAKE_BUILD_TYPE Release)

# Enable compiler optimizations for release builds
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CMAKE_CXX_FLAGS_RELEASE "-O3 -march=native -funroll-loops")
endif()

# Put any CPP files you want to have compiled here. 
add_executable(${PROJECT_NAME}
    cpp/higher_lower_game.cpp 
)

add_executable(LeetCode1 cpp/leetcode-1.cpp)
add_executable(LeetCode9 cpp/leetcode-9.cpp)
add_executable(CPPspeedTest pythonvscpp_speed_test/binary_search.cpp)

# If you have other folders with .h files in them, add those here
target_include_directories(${PROJECT_NAME} PUBLIC
    # ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
    _USE_MATH_DEFINES
    _CRT_SECURE_NO_WARNINGS
)
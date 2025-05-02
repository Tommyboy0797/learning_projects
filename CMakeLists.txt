# CMakeLists.txt — Windows x64 build
cmake_minimum_required(VERSION 3.20)
project(TOMMY LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Put any CPP files you want to have compiled here. 
add_executable(${PROJECT_NAME}
    cpp/higher_lower_game.cpp 
)

# If you have other folders with .h files in them, add those here
target_include_directories(${PROJECT_NAME} PUBLIC
    # ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_definitions(${PROJECT_NAME} PRIVATE
    _USE_MATH_DEFINES
    _CRT_SECURE_NO_WARNINGS
)
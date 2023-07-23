#Setup.
cmake_minimum_required(VERSION 3.27)
cmake_policy(SET CMP0048 NEW)
project(Tutorial VERSION 1.0)
configure_file(TutorialConfig.h.in TutorialConfig.h)
#target_include_directories(${PROJECT_NAME} PUBLIC 
#    ${PROJECT_BINARY_DIR}
#    )
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#Main executable.
add_executable(${PROJECT_NAME} main.cpp)
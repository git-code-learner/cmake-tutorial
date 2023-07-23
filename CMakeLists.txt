#Setup.
cmake_minimum_required(VERSION 3.27)
cmake_policy(SET CMP0048 NEW)
project(Tutorial VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
option(USE_MYMATH "Use tutorial provided math implementation" ON) #Optional.
configure_file(TutorialConfig.h.in TutorialConfig.h)

#Add the MathFunctions library.
add_subdirectory(MathFunctions)

#Main executable.
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC MathFunctions)

#Add the directory to the list of paths (end of file!).
target_include_directories(${PROJECT_NAME} PUBLIC 
"${PROJECT_BINARY_DIR}"
"${PROJECT_SOURCE_DIR}/MathFunctions"
) 
#Setup.
cmake_minimum_required(VERSION 3.27)
cmake_policy(SET CMP0048 NEW)
project(Tutorial VERSION 2.2)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#Choose the compiler.
option(USE_CLANG "Shall clang be used?" OFF)
if(USE_CLANG)
    message(STATUS "Compiler: chosen to build with clang.")
    SET (CMAKE_CXX_COMPILER "/usr/bin/clang++" CACHE STRING "C++ compiler" FORCE)
else()
    message(STATUS "Compiler: chosen to build with g++-12.")
    SET (CMAKE_CXX_COMPILER "/usr/bin/g++-12" CACHE STRING "C++ compiler" FORCE)
endif()

#Turn on the MY_MATH library?
option(USE_MYMATH "Use tutorial provided math implementation" OFF) #Optional.
if(USE_MYMATH)
    add_subdirectory(MathFunctions)
    list(APPEND EXTRA_LIBS MathFunctions)
endif()

#Configure the header file.
configure_file(TutorialConfig.h.in TutorialConfig.h)

#Main executable.
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PUBLIC ${EXTRA_LIBS})

#Add the directory to the list of paths (end of file!).
target_include_directories(${PROJECT_NAME} PUBLIC 
${PROJECT_BINARY_DIR}
) 
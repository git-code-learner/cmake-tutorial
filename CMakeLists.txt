#Setup.
cmake_minimum_required(VERSION 3.27)
cmake_policy(SET CMP0048 NEW)
project(Tutorial VERSION 2.4.2)
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
target_include_directories(${PROJECT_NAME} PUBLIC 
${PROJECT_BINARY_DIR}
)
target_link_libraries(${PROJECT_NAME} PUBLIC ${EXTRA_LIBS})

#Installation.
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(FILES ${PROJECT_BINARY_DIR}/TutorialConfig.h
    DESTINATION include)

#Testing
enable_testing()

# - does the application run
add_test(NAME Runs COMMAND ${PROJECT_NAME} 25)

# - does the usage message work?
add_test(NAME Usage COMMAND ${PROJECT_NAME})
set_tests_properties(Usage
    PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number"
    )

# - define a function to simplify adding tests
function(do_test target arg result)
    add_test(NAME Comp${arg} COMMAND ${target} ${arg})
    set_tests_properties(Comp${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endfunction(do_test)

# - do a bunch of result based tests
do_test(${PROJECT_NAME} 4 "4 is: 2")
do_test(${PROJECT_NAME} 9 "9 is: 3")
do_test(${PROJECT_NAME} 25 "25 is: 5")
do_test(${PROJECT_NAME} 49 "49 is: 7")
do_test(${PROJECT_NAME} 0.0001 "0.0001 is: 0.01")
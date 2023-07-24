#Library MathFunctions
add_library(MathFunctions mysqrt.cpp)
target_include_directories(MathFunctions
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
    )

#Installation.
install(TARGETS MathFunctions DESTINATION lib)
install(FILES MathFunctions.h DESTINATION include)

#Testing.
enable_testing()

#Does the application run?
add_test(NAME Runs COMMAND ${PROJECT_NAME} 25)

#Does the application work?
add_test(NAME Usage COMMAND ${PROJECT_NAME})
set_tests_properties(Usage
  PROPERTIES PASS_REGULAR_EXPRESSION "Usage:.*number"
  )

#Define a function to simplify adding tests.
function(do_test target arg result)
    add_test(NAME Comp${arg} COMMAND ${target} ${arg})
    set_tests_properties(Comp${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endfunction(do_test)

#Do a bunch of testing.
do_test(${PROJECT_NAME} 4 " is 2")
do_test(${PROJECT_NAME} 9 " is 3")
do_test(${PROJECT_NAME} 16 " is 4")
do_test(${PROJECT_NAME} 81 " is 9")
do_test(${PROJECT_NAME} 49 " is 7")
do_test(${PROJECT_NAME} 25 " is 5")
do_test(${PROJECT_NAME} 0.0001 " is 0.01")
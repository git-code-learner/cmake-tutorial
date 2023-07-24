#Library MathFunctions
add_library(MathFunctions mysqrt.cpp)
target_include_directories(MathFunctions
    INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
    )

#Installation.
install(TARGETS MathFunctions DESTINATION lib)
install(FILES MathFunctions DESTINATION include)
cmake_minimum_required (VERSION 3.0)

project (matrix)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable (
    run
    source/main.cpp
    source/basic_matrix_methods.hpp
    source/square_matrix_methods.hpp
    source/setup.hpp
)

if (MSVC)
    target_compile_options (
        run PRIVATE 
        /W4
    )

else ()
    target_compile_options (
        run PRIVATE
        -g -Wall -Wextra -pedantic -Werror
    )

endif ()

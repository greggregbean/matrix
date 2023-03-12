cmake_minimum_required (VERSION 3.0)

project (matrix)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest)

add_executable (
    run
    source/main.cpp
    source/basic_matrix_methods.cpp
    source/square_matrix_methods.cpp
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
        -Wall -Wextra -pedantic -Werror
    )

endif ()

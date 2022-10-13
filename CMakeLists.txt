cmake_minimum_required (VERSION 3.8)

project(Analyzer)

add_subdirectory (Controller)
add_subdirectory (Model)
add_subdirectory (View)

option(USE_TEST "Enter unit test build" OFF)
if (USE_TEST)
    add_subdirectory (Test)
else()
    add_subdirectory (Main)
endif()




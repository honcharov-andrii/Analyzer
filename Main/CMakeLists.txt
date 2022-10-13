cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES "main.cpp")

add_executable (Analyzer ${SOURCE_FILES})

# And also we specify dependence on static library
target_link_libraries(Analyzer View Model Controller)

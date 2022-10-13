cmake_minimum_required (VERSION 3.8)

project(View)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES "view.cpp")
set(HEADER_FILES "view.hpp")

add_library(View STATIC ${HEADER_FILES} ${SOURCE_FILES})
target_include_directories(View PUBLIC ${CMAKE_CURRENT_LIST_DIR})

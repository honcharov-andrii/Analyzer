cmake_minimum_required (VERSION 3.8)

project(Controller)


if (USE_TEST)
  add_definitions(-DUNIT_TEST)
endif()

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES "controller.cpp")
set(HEADER_FILES "controller.hpp")

add_library(Controller STATIC ${HEADER_FILES} ${SOURCE_FILES})
target_include_directories(Controller PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(Controller PUBLIC Model)

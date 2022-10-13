cmake_minimum_required (VERSION 3.8)

project(Model)

set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES "model.cpp")
set(HEADER_FILES "model.hpp")

find_package( Threads REQUIRED )

add_library(Model STATIC ${HEADER_FILES} ${SOURCE_FILES})


target_include_directories(Model PUBLIC ${CMAKE_CURRENT_LIST_DIR})
target_include_directories(Model PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
find_library(CHILKATLIB NAMES libchilkat-9.5.0.a PATHS ${CMAKE_CURRENT_SOURCE_DIR}/lib NO_SYSTEM_ENVIROMENT_PATH)
target_link_libraries(Model ${CHILKATLIB} ${CMAKE_THREAD_LIBS_INIT} ${CMAKE_DL_LIBS})

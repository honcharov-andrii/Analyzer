file(GLOB SRCS *.cpp)
set(CMAKE_CXX_STANDARD 17)

ADD_EXECUTABLE(testController ${SRCS})

TARGET_LINK_LIBRARIES(testController
    Controller
    libgtest
    libgmock
)

add_test(NAME testController
         COMMAND testController)

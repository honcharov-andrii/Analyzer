file(GLOB SRCS *.cpp)
set(CMAKE_CXX_STANDARD 17)
ADD_EXECUTABLE(testModel ${SRCS})

TARGET_LINK_LIBRARIES(testModel
    Model
    libgtest
    libgmock
)

add_test(NAME testModel
         COMMAND testModel)

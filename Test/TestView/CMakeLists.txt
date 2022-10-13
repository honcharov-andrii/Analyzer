file(GLOB SRCS *.cpp)

ADD_EXECUTABLE(testView ${SRCS})

TARGET_LINK_LIBRARIES(testView
    View
    libgtest
    libgmock
)

add_test(NAME testView
         COMMAND testView)

cmake_minimum_required(VERSION 3.8)
project(canManager)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp canManager.cpp canManager.h canMsgBase.cpp canMsgBase.h canRcvMsg.cpp canRcvMsg.h messageStatus.h)
add_executable(canManager ${SOURCE_FILES})

TARGET_LINK_LIBRARIES( ${PROJECT_NAME}
        pthread
        pcan
        )
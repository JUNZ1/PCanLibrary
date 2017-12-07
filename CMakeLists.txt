cmake_minimum_required(VERSION 3.5)
project(canManager)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp canManager.cpp canManager.h canMsgBase.cpp canMsgBase.h canRcvMsg.cpp canRcvMsg.h canSndMsg.cpp canSndMsg.h messageStatus.h packet_container.cpp packet_container.h)
add_executable(canManager ${SOURCE_FILES})

TARGET_LINK_LIBRARIES( ${PROJECT_NAME}
        pthread
        pcan
        )

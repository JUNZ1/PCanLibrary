//
// Created by baran on 10.11.2017.
//

#include "canRcvMsg.h"
void canRcvMsg::start()
{
    stopper=true;
    auto runner=[this]()
    {
        while (stopper)
        {
            msgDelay();
            CAN_Read(m_handle, &msg);
            std::cout<<"Push this-> "<<*this<<std::endl;
            std::lock_guard<std::mutex> myLock(myMutex);
            linkToincomingBuffer->push_back(msg);
        };
        return true;
    };

    stopResult= new std::future<bool>(std::async(std::launch::async,runner));
}

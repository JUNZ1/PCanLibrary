//
// Created by baran on 10.11.2017.
//

#include "canRcvMsg.h"
void canRcvMsg::start()
{
    stopper=true;
    auto runner=[this](){while (stopper) { msgDelay();CAN_Read(canManager::instance()->getHandle(), &msg);std::cout<<*this<<std::endl; };return true;};

    stopResult= new std::future<bool>(std::async(std::launch::async,runner));
}

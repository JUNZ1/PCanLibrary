//
// Created by baran on 03.11.2017.
//
#include <thread>
#include "canMsgBase.h"
#include <future>
canMsgBase::canMsgBase(int milisec): stopper(true),stopped(false)
{
    ms=new std::chrono::milliseconds(milisec);
}

void canMsgBase::start()
{
    stopper=true;
    auto runner=[this](){while (stopper) { msgDelay(); std::cout<<"Test"<<std::endl; };return true;};

    stopResult= new std::future<bool>(std::async(std::launch::async,runner));
}

bool canMsgBase::stop()
{
    stopper=false;
    while(stopResult->wait_for(std::chrono::seconds(1))!=std::future_status::ready);


    return this->stopResult->get();
}

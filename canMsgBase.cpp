//
// Created by baran on 03.11.2017.
//
#include <iostream>
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
    auto runner=[this](){while (stopper) { msgDelay(); std::cout<<"canMsgBase Test For Timer is OK"<<std::endl; };return true;};

    stopResult= new std::future<bool>(std::async(std::launch::async,runner));
}

bool canMsgBase::stop()
{
    stopper=false;
    while(stopResult->wait_for(std::chrono::seconds(1))!=std::future_status::ready)
        std::this_thread::yield();


    return this->stopResult->get();
}


std::ostream& operator<< (std::ostream& os, const canMsgBase& obj) {
    os << "ID:  " <<std::hex<<obj.msg.ID;
    os<<"-- PayLoad--"<<std::endl;
    for(uint a=0;a<obj.msg.LEN;++a)
        os<<std::hex<<(int)obj.msg.DATA[a]<<std::endl;
    return os;
}
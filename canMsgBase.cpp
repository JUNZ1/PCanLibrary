//
// Created by baran on 03.11.2017.
//
#include <iostream>
#include <thread>
#include "canMsgBase.h"
#include <future>
canMsgBase::canMsgBase(int milisec,DWORD msgAdress): stopper(true),stopped(false),m_msgAdress(msgAdress)
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
    return os;
}
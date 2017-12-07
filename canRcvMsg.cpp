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
            std::unique_lock<std::mutex> myLock(canMsgBase::swithMutex);
            canMsgBase::myConditionVariable.wait(myLock,[](){return (canMsgBase::readyFlag);});

            //msgDelay();
            //std::cout<<"Receiver Calisitirildi"<<std::endl;
            std::cout.flush();
            CAN_Read(m_handle, &msg);
            //std::cout<<"Push this-> "<<*this<<std::endl;
            linkToContainer->storeMsg(msg);

            canMsgBase::readyFlag=!canMsgBase::readyFlag;
            canMsgBase::myConditionVariable.notify_all();
        };
        return true;
    };

    stopResult= new std::future<bool>(std::async(std::launch::async,runner));
}

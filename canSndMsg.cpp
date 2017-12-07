//
// Created by baran on 07.12.2017.
//

#include "canSndMsg.h"

void canSndMsg::start()
{
    stopper=true;
    auto runner=[this]()
    {
        while (stopper)
        {
            std::unique_lock<std::mutex> myLock(canMsgBase::swithMutex);
            canMsgBase::myConditionVariable.wait(myLock,[](){return !(canMsgBase::readyFlag);});

            msgDelay();
            //std::cout<<"Sender Calisitirildi"<<std::endl;
            try
            {
                TPCANMsg temporary=linkToContainer->getNextMsgToSend();
                CAN_Write(m_handle,&temporary);
                std::cout<<"Message is send"<<std::endl;
            }
            catch(std::exception& myExcept)
            {
                //std::cout<<myExcept.what()<<std::endl;
            }

            canMsgBase::readyFlag=!canMsgBase::readyFlag;
            canMsgBase::myConditionVariable.notify_all();
        };
        return true;
    };

    stopResult= new std::future<bool>(std::async(std::launch::async,runner));
}

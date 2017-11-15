//
// Created by junzi on 14.11.2017.
//

#include "incoming_Packet.h"
#include <functional>

bool incoming_Packet::found(WORD isThis,TPCANMsg equalToThat)
{
    if(isThis==equalToThat.ID)
        return true;
    else
        return false;
}

bool deneme(TPCANMsg)
{

    return true;
}


incoming_Packet::incoming_Packet(int delayMs,WORD msgID) :canMsgBase(delayMs),idOfInterest(msgID){}





void incoming_Packet::start()
{

    stopper=true;

    auto runner=[this]()
    {
        while (stopper)
        {
            auto findThis=std::bind(&incoming_Packet::found,idOfInterest,std::placeholders::_1);
            auto deneme2=std::bind(deneme,std::placeholders::_1);
            msgDelay();
            std::find_if(canManager::instance()->incomingBuffer.begin(),canManager::instance()->incomingBuffer.end(),deneme2);
        };
        return true;
    };

    stopResult= new std::future<bool>(std::async(std::launch::async,runner));
}


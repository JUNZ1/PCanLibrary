//
// Created by junzi on 14.11.2017.
//

#include "incoming_Packet.h"
#include <functional>

bool incoming_Packet::found(WORD isThis,TPCANMsg equalToThat)
{
    if(isThis==equalToThat.ID)
    {
        std::cout<<"Bulundu"<<std::endl;
        return true;
    }

    else
    {
       // std::cout<<"Bulunmadi"<<std::endl;
        return false;
    }

}


incoming_Packet::incoming_Packet(int delayMs,WORD msgID) :canMsgBase(delayMs),idOfInterest(msgID){}



//(void(Foo::*)(int, int))
//(bool(incoming_Packet::*)(WORD, TPCANMsgn))
void incoming_Packet::start()
{

    stopper=true;

    auto runner=[this]()
    {
        while (stopper)
        {
            auto findThis=std::bind(&incoming_Packet::found,this,idOfInterest,std::placeholders::_1);
            msgDelay();

            std::vector<TPCANMsg>::iterator myIterator=std::find_if(canManager::instance()->incomingBuffer.begin(),canManager::instance()->incomingBuffer.end(),findThis);
            if(myIterator!=canManager::instance()->incomingBuffer.end())
            canManager::instance()->incomingBuffer.erase(myIterator);

        };
        return true;
    };

    stopResult= new std::future<bool>(std::async(std::launch::async,runner));
}


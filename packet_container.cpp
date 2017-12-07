//
// Created by junzi on 16.11.2017.
//

#include "packet_container.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void packet_container::storeMsg(TPCANMsg msg)
{
    if(registeredINMsgSet.find(msg.ID)!=registeredINMsgSet.end())
    {
        //std::cout<<"---Msg is Stored---"<<std::endl;
        storedInMessages[msg.ID].push_back(msg);
    }

}

TPCANMsg packet_container::getMsgById(DWORD seekThis)
{
    TPCANMsg tempMsg;

    if(registeredINMsgSet.find(seekThis)!=registeredINMsgSet.end())
    {
        if(storedInMessages[seekThis].size()!=0)
        {
            tempMsg=storedInMessages[seekThis].at(0);
            storedInMessages[seekThis].pop_front();
            return tempMsg;
        }
        else
        {
            std::stringstream stream;
            stream << std::hex << seekThis;
            std::string result( stream.str() );

            throw std::logic_error ("No New Message !!! ->  0x"+result);
        }

    }
    else
    {
        std::stringstream stream;
        stream << std::hex << seekThis;
        std::string result( stream.str() );
        throw std::logic_error ("This ID is not Registered!!! -> 0x"+result);
    }

}

void packet_container::pumpOutMsg(TPCANMsg messageToBeSend)
{
     if(registeredOutMsgSet.find(messageToBeSend.ID)!=registeredOutMsgSet.end())
     {
         storedOutMessages.push_back(messageToBeSend);
     }
     else
     {
         std::stringstream stream;
         stream << std::hex << messageToBeSend.ID;
         std::string result( stream.str() );

         throw std::logic_error ("UnRegistered Message is Tried to Send!!:  0x"+result);
     }
}

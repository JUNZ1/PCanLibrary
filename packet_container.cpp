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
        storedMessages[msg.ID].push_back(msg);
    }

}

TPCANMsg packet_container::getMsgById(DWORD seekThis)
{
    TPCANMsg tempMsg;

    if(registeredINMsgSet.find(seekThis)!=registeredINMsgSet.end())
    {
        if(storedMessages[seekThis].size()!=0)
        {
            tempMsg=storedMessages[seekThis].at(0);
            storedMessages[seekThis].pop_front();
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

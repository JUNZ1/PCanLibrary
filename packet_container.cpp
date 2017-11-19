//
// Created by junzi on 16.11.2017.
//

#include "packet_container.h"

void packet_container::storeMsg(TPCANMsg msg)
{
    if(registeredMsg.find(msg.ID)!=registeredMsg.end())
        storedMessages[msg.ID].push_back(msg);
}

TPCANMsg packet_container::getMsgById(DWORD seekThis)
{
    TPCANMsg tempMsg;

    if(registeredMsg.find(seekThis)!=registeredMsg.end())
    {
        if(storedMessages[seekThis].size()!=0)
        {
            tempMsg=storedMessages[seekThis].at(0);
            storedMessages[seekThis].pop_front();
            return tempMsg;
        }
        else
            throw std::logic_error ("No New Message !!!");
    }
    else
    {
        throw std::logic_error ("This ID is not Registered!!!");
    }

}

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
            msgDelay();
            //will be implemented here
        };
        return true;
    };

    stopResult= new std::future<bool>(std::async(std::launch::async,runner));
}

//
// Created by baran on 10.11.2017.
//

#include "canRcvMsg.h"
void canRcvMsg::start()
{
    msgDelay();
    CAN_Read(canManager::instance()->getHandle(), &msg);
}
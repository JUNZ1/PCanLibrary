//
// Created by baran on 07.12.2017.
//

#ifndef CANMANAGER_CANSNDMSG_H
#define CANMANAGER_CANSNDMSG_H
#include "canMsgBase.h"
#include "packet_container.h"
#include <deque>
class canSndMsg :public canMsgBase
{
public:
    canSndMsg(int milliSeconds,HANDLE handleInput,packet_container* link):canMsgBase(milliSeconds),m_handle(handleInput),linkToContainer(link){}
    virtual void start();
    virtual ~canSndMsg(){}
private:
    HANDLE m_handle;
    packet_container* linkToContainer;
};


#endif //CANMANAGER_CANSNDMSG_H

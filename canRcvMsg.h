//
// Created by baran on 10.11.2017.
//

#ifndef CANMANAGER_CANRCVMSG_H
#define CANMANAGER_CANRCVMSG_H
#include "canMsgBase.h"
#include <vector>
#include "packet_container.h"
class canRcvMsg: public canMsgBase {

public:
    canRcvMsg(int miliSeconds,HANDLE handleInput,packet_container* link):canMsgBase(miliSeconds),linkToContainer(link){}
    virtual void start();

private:
    HANDLE m_handle;
    std::vector<TPCANMsg>* linkToincomingBuffer;
    packet_container* linkToContainer;
};


#endif //CANMANAGER_CANRCVMSG_H

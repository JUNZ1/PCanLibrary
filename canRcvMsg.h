//
// Created by baran on 10.11.2017.
//

#ifndef CANMANAGER_CANRCVMSG_H
#define CANMANAGER_CANRCVMSG_H
#include "canMsgBase.h"
#include <vector>

class canRcvMsg: public canMsgBase {

public:
    canRcvMsg(int miliSeconds,HANDLE handleInput,std::vector<TPCANMsg>* linkArg):canMsgBase(miliSeconds),m_handle(handleInput),linkToincomingBuffer(linkArg){}
    virtual void start();

private:
    HANDLE m_handle;
    std::vector<TPCANMsg>* linkToincomingBuffer;
};


#endif //CANMANAGER_CANRCVMSG_H

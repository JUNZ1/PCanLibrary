//
// Created by baran on 10.11.2017.
//

#ifndef CANMANAGER_CANRCVMSG_H
#define CANMANAGER_CANRCVMSG_H
#include "canMsgBase.h"


class canRcvMsg: public canMsgBase {

public:
    canRcvMsg(int miliSeconds,DWORD msgAdress,HANDLE handleInput):canMsgBase(miliSeconds,msgAdress),m_handle(handleInput){}
    virtual void start();

private:
    HANDLE m_handle;
};


#endif //CANMANAGER_CANRCVMSG_H

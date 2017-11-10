//
// Created by baran on 10.11.2017.
//

#ifndef CANMANAGER_CANRCVMSG_H
#define CANMANAGER_CANRCVMSG_H
#include "canMsgBase.h"

class canRcvMsg: public canMsgBase {

public:
    canRcvMsg(int miliSeconds,DWORD msgAdress):canMsgBase(miliSeconds,msgAdress){}
    virtual void start();

private:

};


#endif //CANMANAGER_CANRCVMSG_H

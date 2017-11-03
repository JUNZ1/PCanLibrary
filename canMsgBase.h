//
// Created by baran on 03.11.2017.
//

#ifndef CANMANAGER_CANMSGBASE_H
#define CANMANAGER_CANMSGBASE_H
#include <iostream>
#include <libpcan.h>

class canMsgBase {
public:
    canMsgBase(DWORD* inputAdress){m_handlerAddres=inputAdress;}
protected:
    DWORD* m_handlerAddres= nullptr;
    TPCANMsg msg;
};


#endif //CANMANAGER_CANMSGBASE_H

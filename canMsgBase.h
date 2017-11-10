//
// Created by baran on 03.11.2017.
//

#ifndef CANMANAGER_CANMSGBASE_H
#define CANMANAGER_CANMSGBASE_H
#include <iostream>
#include <libpcan.h>
#include "pcan.h"
#include <chrono>
#include <future>
#include "canManager.h"

class canMsgBase {
public:
    canMsgBase(int,DWORD);
    virtual void start();
    bool stop();
protected: //ileride protected yapilacak inheritten sonra
    DWORD* m_handlerAddres= nullptr;
    TPCANMsg msg;
    void msgDelay(){std::this_thread::sleep_until(std::chrono::steady_clock::now()+*ms);}
private:
    std::chrono::milliseconds* ms;
    bool stopper;
    bool stopped;
    std::future<bool>* stopResult;
private:
    DWORD m_msgAdress;
};




#endif //CANMANAGER_CANMSGBASE_H

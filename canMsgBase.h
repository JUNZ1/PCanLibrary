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


class canMsgBase {
public:
    canMsgBase(int,DWORD);
    virtual void start();
    bool stop();
    friend std::ostream& operator<<(std::ostream&, const canMsgBase&);
protected: //ileride protected yapilacak inheritten sonra
    DWORD* m_handlerAddres= nullptr;
    TPCANMsg msg;
    void msgDelay(){std::this_thread::sleep_until(std::chrono::steady_clock::now()+*ms);}
    bool stopper;
    bool stopped;
    std::future<bool>* stopResult;
private:
    std::chrono::milliseconds* ms;
    DWORD m_msgAdress;

};

std::ostream& operator<<(std::ostream&, const canMsgBase&);


#endif //CANMANAGER_CANMSGBASE_H

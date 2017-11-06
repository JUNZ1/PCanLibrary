//
// Created by baran on 03.11.2017.
//

#ifndef CANMANAGER_CANMSGBASE_H
#define CANMANAGER_CANMSGBASE_H
#include <iostream>
#include <libpcan.h>
#include <chrono>
#include <future>


class canMsgBase {
public:
    canMsgBase(int);
public: //ileride protected yapilacak inheritten sonra
    DWORD* m_handlerAddres= nullptr;
    TPCANMsg msg;
    void msgDelay(){std::this_thread::sleep_until(std::chrono::steady_clock::now()+*ms);}
    void start();
    bool stop();
private:
    std::chrono::milliseconds* ms;
    bool stopper;
    bool stopped;
    std::future<bool>* stopResult;
};




#endif //CANMANAGER_CANMSGBASE_H


/*
 *     This code will be implemented
 *     chrono::milliseconds ms(500);
       this_thread::sleep_until(chrono::steady_clock::now()+ms);
 */
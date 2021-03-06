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
#include <mutex>





class canMsgBase {
public:
    canMsgBase(int);
    virtual void start();
    bool stop();
    friend std::ostream& operator<<(std::ostream&, const canMsgBase&);

    static bool readyFlag;
    static std::mutex swithMutex;
    static std::condition_variable myConditionVariable;

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

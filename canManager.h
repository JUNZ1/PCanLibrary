//
// Created by baran on 03.11.2017.
//

#ifndef CANMANAGER_CANMANAGER_H
#define CANMANAGER_CANMANAGER_H
#include <iostream>
#include <libpcan.h>
#include "canRcvMsg.h"
class canManager {
private:
    static canManager* s_instance;
    canManager(){std::cout<<"Can Manager is Created"<<std::endl;};
    ~canManager(){delete s_instance;delete allReceiver;}
    HANDLE m_handle;
    DWORD m_status;
    void writeStatus();
    canRcvMsg* allReceiver;
    void registerReceiver(){allReceiver=new canRcvMsg(100,m_handle);}
public:
    canManager(canManager&)= delete;
    canManager(canManager&&)= delete;
    static canManager* instance();
    void openCan(int number){m_handle=CAN_Open(HW_USB, number);if(m_handle==0) throw std::out_of_range ("can index is= out_of_range");};
    void initCAN();
    void closeCan(){CAN_Close(m_handle);writeStatus();}
    HANDLE getHandle(){return m_handle;}
    const int buffPacketLimit=300;
};




#endif //CANMANAGER_CANMANAGER_H

//
// Created by baran on 03.11.2017.
//

#ifndef CANMANAGER_CANMANAGER_H
#define CANMANAGER_CANMANAGER_H
#include <iostream>
#include <libpcan.h>

class canManager {
private:
    static canManager* s_instance;
    canManager(){std::cout<<"Can Manager is Created"<<std::endl;};
    HANDLE m_handle;
    DWORD m_status;
    void writeStatus();

public:
    HANDLE getHandleNumber(){return m_handle;}
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

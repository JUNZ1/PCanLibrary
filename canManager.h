//
// Created by baran on 03.11.2017.
//

#ifndef CANMANAGER_CANMANAGER_H
#define CANMANAGER_CANMANAGER_H
#include <iostream>
#include <mutex>
#include <vector>
#include <libpcan.h>
#include "pcan.h"
#include "canRcvMsg.h"
#include "canSndMsg.h"
#include "messageStatus.h"
#include "packet_container.h"
class canManager: public packet_container {
private:
    static canManager* s_instance;
    canManager(){std::cout<<"Can Manager is Created"<<std::endl;}
    virtual ~canManager(){delete s_instance;delete allReceiver;}
    HANDLE m_handle;
    DWORD m_status;
    void writeStatus();
    canRcvMsg* allReceiver;
    canSndMsg* allSender;
    void registerReceiver(){allReceiver=new canRcvMsg(5,m_handle,this);}
    void registerSender(){allSender=new canSndMsg(5,m_handle,this);}


public:
    canManager(canManager&)= delete;
    canManager(canManager&&)= delete;
    static canManager* instance();
    void openCan(int number){m_handle=CAN_Open(HW_USB, number);if(m_handle==0) throw std::out_of_range ("can index is= out_of_range");}
    void initCAN();
    void closeCan(){myCAN::tolls4All::writeStatus(CAN_Close(m_handle));allReceiver->stop();}
    HANDLE getHandle(){return m_handle;}
    const int buffPacketLimit=300;
    void writeAllIncomingBuff();
    std::vector<TPCANMsg> incomingBuffer;
};

std::ostream& operator<<(std::ostream&, const TPCANMsg&);


#endif //CANMANAGER_CANMANAGER_H

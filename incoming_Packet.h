//
// Created by junzi on 14.11.2017.
//

#ifndef CANMANAGER_INCOMING_PACKET_H
#define CANMANAGER_INCOMING_PACKET_H

#include "canMsgBase.h"
#include <libpcan.h>
#include <vector>
#include <algorithm>
#include <mutex>
#include "pcan.h"
#include "canManager.h"


class incoming_Packet :public  canMsgBase{

public:
    incoming_Packet(int,WORD);
    virtual void start();
private:
    WORD idOfInterest;


    bool found(WORD,TPCANMsg);

};


#endif //CANMANAGER_INCOMING_PACKET_H

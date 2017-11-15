//
// Created by junzi on 14.11.2017.
//

#ifndef CANMANAGER_INCOMING_PACKET_H
#define CANMANAGER_INCOMING_PACKET_H

#include "canMsgBase.h"
#include <libpcan.h>
#include "pcan.h"
#include <vector>
#include "canManager.h"
#include <algorithm>

class incoming_Packet :public  canMsgBase{

public:
    incoming_Packet(int,WORD);

private:
    WORD idOfInterest;

    virtual void start();
    bool found(WORD,TPCANMsg);

};


#endif //CANMANAGER_INCOMING_PACKET_H

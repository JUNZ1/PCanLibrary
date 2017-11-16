//
// Created by junzi on 16.11.2017.
//

#ifndef CANMANAGER_PACKET_CONTAINER_H
#define CANMANAGER_PACKET_CONTAINER_H

#include <libpcan.h>
#include <map>
#include <deque>
#include <set>
#include <algorithm>
#include <mutex>
#include "pcan.h"

class packet_container
{
    public:
        void registerMsg(DWORD input){registeredMsg.insert(input);}
        void storeMsg(TPCANMsg msg);
        TPCANMsg getMsgById(DWORD);
    private:
        std::map<DWORD,std::deque<TPCANMsg>> storedMessages;
        std::set<DWORD> registeredMsg;
};


#endif //CANMANAGER_PACKET_CONTAINER_H

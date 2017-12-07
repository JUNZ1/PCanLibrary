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
#include "deque"

class packet_container
{
    public:
        void registerINMsg(DWORD input){registeredINMsgSet.insert(input);}
        void registerOutMsg(DWORD input){registeredOutMsgSet.insert(input);}
        void pumpOutMsg(TPCANMsg);
        void storeMsg(TPCANMsg msg);
        TPCANMsg getMsgById(DWORD);
    private:
        std::map<DWORD,std::deque<TPCANMsg>> storedInMessages;
        std::deque<TPCANMsg> storedOutMessages;
        std::set<DWORD> registeredINMsgSet;
        std::set<DWORD> registeredOutMsgSet;
};


#endif //CANMANAGER_PACKET_CONTAINER_H

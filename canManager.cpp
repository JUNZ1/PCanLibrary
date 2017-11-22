//
// Created by baran on 03.11.2017.
//

#include "canManager.h"

canManager *canManager::s_instance = 0;


canManager* canManager::instance()
{
    if (!s_instance)
    {
        s_instance = new canManager;
    }

    return s_instance;
}

void canManager::initCAN()
{
    registerReceiver();
    m_status=CAN_Init(m_handle, CAN_BAUD_250K, CAN_INIT_TYPE_EX);
    writeStatus();
    allReceiver->start();

}


std::ostream& operator<< (std::ostream& os, const TPCANMsg& obj) {
    os << "ID:  " <<std::hex<<obj.ID;
    os<<"-- PayLoad--"<<std::endl;
    for(uint a=0;a<obj.LEN;++a)
        os<<std::hex<<(int)obj.DATA[a]<<std::endl;
    return os;
}

void canManager::writeAllIncomingBuff()
{
    std::cout<<"\n\nPrint All Buffer"<<std::endl;
    for(auto index:incomingBuffer)
        std::cout<<index<<std::endl;
}
void canManager::writeStatus()
{
    switch (m_status)
    {
        case CAN_ERR_OK:
        {
            std::cout<<"No_ERROR"<<std::endl;
            break;
        }

        case CAN_ERR_XMTFULL:
        {
            std::cout<<"CAN_ERR_XMTFULL"<<std::endl;
            break;
        }

        case CAN_ERR_OVERRUN:
        {
            std::cout<<"CAN_ERR_OVERRUN"<<std::endl;
            break;
        }

        case CAN_ERR_BUSLIGHT:
        {
            std::cout<<"CAN_ERR_BUSLIGHT"<<std::endl;
            break;
        }

        case CAN_ERR_BUSHEAVY:
        {
            std::cout<<"CAN_ERR_BUSHEAVY"<<std::endl;
            break;
        }

        case CAN_ERR_BUSOFF:
        {
            std::cout<<"CAN_ERR_BUSOFF"<<std::endl;
            break;
        }

        case CAN_ERR_QRCVEMPTY:
        {
            std::cout<<"CAN_ERR_QR  auto myFonk=std::bind(oku,h,msg);CVEMPTY"<<std::endl;
            break;
        }

        case CAN_ERR_QXMTFULL:
        {
            std::cout<<"CAN_ERR_QXMTFULL"<<std::endl;
            break;
        }

        case CAN_ERR_REGTEST:
        {
            std::cout<<"CAN_ERR_REGTEST"<<std::endl;
            break;
        }

        case CAN_ERR_NOVXD:
        {
            std::cout<<"CAN_ERR_NOVXD"<<std::endl;
            break;
        }
        case CAN_ERR_RESOURCE:
        {
            std::cout<<"CAN_ERR_RESOURCE"<<std::endl;
            break;
        }
        case CAN_ERR_ILLPARAMTYPE:
        {
            std::cout<<"CAN_ERR_ILLPARAMTYPE"<<std::endl;
            break;
        }
        case CAN_ERR_ILLPARAMVAL:
        {
            std::cout<<"CAN_ERR_ILLPARAMVAL"<<std::endl;
            break;
        }
        case CAN_ERRMASK_ILLHANDLE:
        {
            std::cout<<"CAN_ERRMASK_ILLHANDLE"<<std::endl;
            break;
        }
        default:
            break;
    }
}
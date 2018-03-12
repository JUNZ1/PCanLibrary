#ifndef STATUSHANDLER_H
#define STATUSHANDLER_H

class someTools
{
public:
    void handleStatus(DWORD m_status)
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
};
#endif //STATUSHANDLER_H

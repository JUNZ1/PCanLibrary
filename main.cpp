#include <iostream>
#include "canManager.h"
#include "canRcvMsg.h"
#include <map>

void test_send123()
{
    TPCANMsg msg;
       msg.ID = 0x123;
       msg.MSGTYPE= MSGTYPE_EXTENDED;
       msg.LEN = 3;
       msg.DATA[0] = 0x01;
       msg.DATA[1] = 0x02;
       msg.DATA[2] = 0x03;
       canManager::instance()->registerOutMsg(0x123);
       while(true)
       {
           std::this_thread::sleep_for(std::chrono::milliseconds(500));
           try
           {
                canManager::instance()->pumpOutMsg(msg);
           }
           catch(std::exception& myExcept)
           {
               std::cout<<myExcept.what()<<std::endl;
           }

       }
}

void test5()
{

    TPCANMsg msg;
       msg.ID = 0x123;
       msg.MSGTYPE= MSGTYPE_EXTENDED;
       msg.LEN = 3;
       msg.DATA[0] = 0x01;
       msg.DATA[1] = 0x02;
       msg.DATA[2] = 0x03;
    try
    {
        canManager::instance()->openCan(0);
        canManager::instance()->registerINMsg(0x152);
        canManager::instance()->registerINMsg(0x160);
        canManager::instance()->initCAN();
        std::chrono::milliseconds ms(10);
        int say=0;
        std::thread t1(test_send123);
        t1.detach();
        while(true)
        {
          std::this_thread::sleep_until(std::chrono::steady_clock::now()+ms);
            ++say;
            try
            {
                std::cout<<"\n***Mesaj Geldi***\n"<<canManager::instance()->getMsgById(0x152);
                std::cout<<"\n***Mesaj Geldi***\n"<<canManager::instance()->getMsgById(0x160);
            }
            catch (std::logic_error printThis)
            {
                //std::cout<<printThis.what()<<std::endl;
            }
        }

        canManager::instance()->closeCan();
        canManager::instance()->writeAllIncomingBuff();
    }
    catch (std::out_of_range a)
    {
        std::cout<<a.what()<<std::endl;
    }

}



int main() {

    test5();
    std::cout<<"End Of Program"<<std::endl;
    return 0;
}

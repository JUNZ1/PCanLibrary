#include <iostream>
#include "canManager.h"
#include "canRcvMsg.h"
#include <map>


void test2()
{

    try
    {
        canManager::instance()->openCan(1);
        canManager::instance()->initCAN();

        int duration=100;
        std::chrono::milliseconds ms(duration);
        int say=0;
        while(say<30)
        {
            std::this_thread::sleep_until(std::chrono::steady_clock::now()+ms);
            ++say;
        }

        canManager::instance()->closeCan();
        canManager::instance()->writeAllIncomingBuff();
    }
    catch (std::out_of_range a)
    {
        std::cout<<a.what()<<std::endl;
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
        canManager::instance()->registerOutMsg(0x123);
        canManager::instance()->initCAN();
        std::chrono::milliseconds ms(10);
        int say=0;

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
          if(say==10)
          {
            std::cout<<std::dec<<say<<std::endl;
            say=0;

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

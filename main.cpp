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

    try
    {
        canManager::instance()->openCan(0);
        canManager::instance()->registerINMsg(0x152);
        canManager::instance()->registerINMsg(0x160);
        canManager::instance()->initCAN();
        std::chrono::milliseconds ms(50);
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
                std::cout<<printThis.what()<<std::endl;
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

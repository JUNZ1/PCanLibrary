#include <iostream>
#include "canManager.h"
#include "canRcvMsg.h"
#include "incoming_Packet.h"


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

void test3()
{
    incoming_Packet deneme(1,0x0f);
}

void test4()
{

    try
    {
        incoming_Packet incomingHandler(10,0x152);
        incomingHandler.start();
        canManager::instance()->openCan(1);
        canManager::instance()->initCAN();

        std::chrono::milliseconds ms(100);
        int say=0;
        while(say<30)
        {
            std::this_thread::sleep_until(std::chrono::steady_clock::now()+ms);
            ++say;
        }

        incomingHandler.stop();
        canManager::instance()->closeCan();
        canManager::instance()->writeAllIncomingBuff();
    }
    catch (std::out_of_range a)
    {
        std::cout<<a.what()<<std::endl;
    }

}

int main() {


    test4();
    return 0;
}

#include <iostream>
#include "canManager.h"
#include "canRcvMsg.h"


int main() {
    std::cout << "Hello, World!" << std::endl;

    try
    {
        canManager::instance()->openCan(1);
        canManager::instance()->initCAN();

        int duration=250;
        canRcvMsg incoming(duration,0x0f,canManager::instance()->getHandle());
        incoming.start();
        std::chrono::milliseconds ms(duration);
        int say=0;
            while(say<30)
            {
                std::this_thread::sleep_until(std::chrono::steady_clock::now()+ms);
                ++say;
            }
        incoming.stop();

        canManager::instance()->closeCan();
    }
    catch (std::out_of_range a)
    {
        std::cout<<a.what()<<std::endl;
    }



    return 0;
}

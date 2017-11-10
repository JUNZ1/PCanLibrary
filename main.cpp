#include <iostream>
#include "canRcvMsg.h"



int main() {
    std::cout << "Hello, World!" << std::endl;

    canManager::instance()->openCan(0);
    canManager::instance()->initCAN();

    int duration=250;
    canRcvMsg incoming(duration,0x0f);
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
    return 0;
}

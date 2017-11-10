#include <iostream>
#include "canMsgBase.h"


void unit_test_START()
{
    int duration=100;
    canMsgBase deneme(duration,0x23);
    //deneme.start();
    int say=0;
    std::chrono::milliseconds ms(duration);
    while(say<30)
    {
        std::cout<<say<<std::endl;

        std::this_thread::sleep_until(std::chrono::steady_clock::now()+ms);
        ++say;
    }

    //std::cout<<"Bitti... Sonuc= "<<deneme.stop()<<std::endl;
}
int main() {
    std::cout << "Hello, World!" << std::endl;

    /*
    canManager::instance()->openCan(0);
    canManager::instance()->initCAN();
    canManager::instance()->closeCan();
    */

    return 0;
}
#include <iostream>
#include "canManager.h"
int main() {
    std::cout << "Hello, World!" << std::endl;

    canManager::instance()->openCan(0);
    canManager::instance()->initCAN();
    canManager::instance()->closeCan();
/*
 *     This code will be implemented
 *     chrono::milliseconds ms(500);
       this_thread::sleep_until(chrono::steady_clock::now()+ms);
 */
    return 0;
}
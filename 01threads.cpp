#include <thread>
#include <iostream>

void fuction1() {
    std::cout << "Called by thread1" << std::endl;
}

void function2() {
    std::cout << "Called by thread2" << std::endl;
}

int main() {
    
    std::thread thread1(fuction1);
    std::thread thread2(function2);

    // Wait for threads to finish
    thread1.join();
    thread2.join();

    std::cout << "Threads have finished execution." << std::endl;

    return 0;
}
#include <iostream>
#include <thread>
using namespace std;

int sharedVariable = 0;

void function1() {
    sharedVariable++;
    std::cout<<"Value Printed:\t"<<sharedVariable<<std::endl;
}

int main() {
    
    std::thread threads[5];

    for(int i = 0; i < 5; ++i) {
        threads[i] = std::thread(function1);
    }

    for(int i = 0; i < 5; ++i) {
        threads[i].join();
    }

    return 0;
}
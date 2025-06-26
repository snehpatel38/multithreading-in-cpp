#include <iostream>
#include <thread>
#include <chrono>

void Add50Numbers() {
    int add50 = 0;

    for(int i = 1; i <= 50; ++i) {
        add50 += i;
    }

    std::cout << "Sum of first 50 numbers: " << add50 << std::endl;
}

void Add100Numbers() {
    int add100 = 0;

    for(int i = 1; i <= 100; ++i) {
        add100 += i;
    }

    std::cout << "Sum of first 100 numbers: " << add100 << std::endl;
}   

int main() {

    std::chrono::time_point<std::chrono::system_clock> start_time, end_time;

    start_time = std::chrono::system_clock::now();
    Add50Numbers();
    Add100Numbers();
    end_time = std::chrono::system_clock::now();

    std::cout<<"Time taken by sequential execution: "<<(end_time - start_time).count() << std::endl;

    
    start_time = std::chrono::system_clock::now();
    std::thread t1(Add50Numbers);
    std::thread t2(Add100Numbers);
    t1.join();
    t2.join();
    end_time = std::chrono::system_clock::now();

    std::cout<<"Time taken by multithreaded execution: "<<(end_time - start_time).count() << std::endl;

    return 0;
}
#include <iostream>
#include <thread>

void AddTwoNumbers(int a, int b) {
    std::cout << "Sum: " << (a + b) << std::endl;
}

void MultiplyTwoNumbers(int a, int b) {
    std::cout << "Product: " << (a * b) << std::endl;
}

int main() {
    
    int x = 5;
    int y = 10;

    std::thread t1(AddTwoNumbers, x, y);
    std::thread t2(MultiplyTwoNumbers, x, y);

    // Wait for threads to finish
    t1.join();
    t2.join();

    return 0;
}
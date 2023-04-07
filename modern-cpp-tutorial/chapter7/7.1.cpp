#include <iostream>
#include <thread>

int main(int argc, const char** argv) {
    std::thread t([]() {
        std::cout << "hello wolrd." << std::endl;
    });
    t.join();
    return 0;
}
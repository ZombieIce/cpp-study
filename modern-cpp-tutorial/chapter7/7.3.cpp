#include <iostream>
#include <mutex>
#include <thread>

int v = 1;

void critical_section(int change_v, int cur_id) {
    static std::mutex mtx;
    std::unique_lock<std::mutex> lock(mtx);
    v = change_v;
    std::cout << cur_id << ": " <<  v << std::endl;
    lock.unlock();

    lock.lock();
    v += 1;
    std::cout << cur_id << ": " << v << std::endl;
}

int main(int argc, const char** argv) {
    std::thread t1(critical_section, 2, 0), t2(critical_section, 3, 1);
    t1.join();
    t2.join();
    return 0;
}
#include <iostream>
#include <atomic>
#include <thread>
#include <vector>

int main(int argc, const char** argv) {
    std::atomic<int> counter = {0};
    std::vector<std::thread> vt;
    for (int i = 0; i < 100; ++i) {
        vt.emplace_back([&](){
            counter.fetch_add(1, std::memory_order_relaxed);
        });
    }

    for (auto &t : vt) {
        t.join();
    }

    std::cout << "current counter: " << counter << std::endl;

    std::atomic<int*> ptr(nullptr);
    int v;
    std::thread producer([&](){
        int* p = new int(42);
        v = 1024;
        ptr.store(p, std::memory_order_release);
    });

    std::thread consumer([&](){
        int* p;
        while (!(p = ptr.load(std::memory_order_consume)));
        std::cout << "p: " << *p << std::endl;
        std::cout << "v: " << v << std::endl;
    });

    producer.join();
    consumer.join();


    std::vector<int> v1;
    std::atomic<int> flag = {0};
    std::thread release([&](){
        v1.push_back(42);
        flag.store(1, std::memory_order_release);
    });
    std::thread acrel([&](){
        int expected = 1;
        while (!flag.compare_exchange_strong(expected, 2, std::memory_order_acq_rel)) {
            expected = 1;
        }
    });

    std::thread acquire([&](){
        while (flag.load(std::memory_order_acquire) < 2);
        std::cout << v1.at(0) << std::endl;
    });

    release.join();
    acrel.join();
    acquire.join();

    counter = 0;
    vt = {};
    for (int i = 0; i < 100; ++i) {
        vt.emplace_back([&](){
            counter.fetch_add(1, std::memory_order_seq_cst);
        });
    }

    for (auto& t: vt) {
        t.join();
    }
    std::cout << "current counter: " << counter << std::endl;
    return 0;
}
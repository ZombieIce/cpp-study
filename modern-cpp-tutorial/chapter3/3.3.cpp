#include <functional>
#include <iostream>

int foo(int a, int b, int c) {
    return a + b + c;
}

int main(int argc, const char** argv) {
    auto bindFoo = std::bind(foo, std::placeholders::_1, 1, 2);
    std::cout << bindFoo(1) << std::endl;
    return 0;
}
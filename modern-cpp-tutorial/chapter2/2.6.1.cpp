#include <iostream>

class Base {
public:
    int value1;
    int value2;
    Base() {
        value1 = 1;
    }
    Base(int value):Base() {
        value2 = value;
    }
};

class SubClass: public Base {
public:
    using Base::Base;
};


int main(int argc, const char** argv) {
    Base b(2);
    std::cout << b.value1 << std::endl;
    std::cout << b.value2 << std::endl;

    SubClass s(3);
    std::cout << s.value1 << std::endl;
    std::cout << s.value2 << std::endl;

    return 0;
}
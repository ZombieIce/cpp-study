#include <array>
#include <initializer_list>
#include <iostream>
#include <string>
#include <utility>

struct Point {
    double m_x, m_y, m_z;
};

int makeSum(std::initializer_list<int> values) {
    int total {0};
    for (int i : values) {
        total += i;
    }
    return total;
}

int main(int argc, const char** argv) {
    Point point;
    point.m_x = 1.0; point.m_y = 2.0; point.m_z = 3.0;
    auto [x, y, z] { point };
    std::cout << x << " " << y << " " << z << std::endl;
    
    std::array<int, 3> values {11, 22, 33};
    auto [x1, y1, z1] { values};
    std::cout << x1 << " " << y1 << " " << z1 << std::endl;

    std::pair<std::string, int> myPair { "hello", 5};
    auto [theString, theInt] { myPair};
    std::cout << theString << " " << theInt << std::endl;


    std::array<int, 4> arr {1, 2, 3, 4};
    for (int i : arr) {
        std::cout << i << std::endl;
    }

    std::cout << "====================" << std::endl;

    for (std::array<int, 4> arr {1, 2, 3, 4}; int i : arr) {
        std::cout << i << std::endl;
    }

    int a { makeSum({1, 2, 3})};
    int b { makeSum({10, 20, 30, 40, 50, 60})};
    std::cout << a << " " << b << std::endl;
    
    return 0;
}
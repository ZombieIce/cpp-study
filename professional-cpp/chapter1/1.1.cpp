#include <iostream>
#include <compare>
#include <string>

auto addNumbers(int number1, int number2) {
    std::cout << "Entering function " << __func__ << std::endl;
    return number1 + number2;
}

[[nodiscard("Some explanation")]] int func() {
    return 42;
}


int main(int argc, const char** argv) {
    int i {11};
    std::strong_ordering result { i <=> 0};
    if (result == std::strong_ordering::less) {std::cout << "less" << std::endl;}
    if (result == std::strong_ordering::greater) {std::cout << "greater" << std::endl;}
    if (result == std::strong_ordering::equal) {std::cout << "equal" << std::endl;}

    double f {2.1};
    std::partial_ordering p_result { f <=> 0};
    if (p_result == std::partial_ordering::less) {std::cout << "partial less" << std::endl;}
    if (p_result == std::partial_ordering::greater) {std::cout << "partial greater" << std::endl;}
    if (p_result == std::partial_ordering::equivalent) {std::cout << "partial equal" << std::endl;}
    if (p_result == std::partial_ordering::unordered) {std::cout << "partial unordered" << std::endl;}

    if (std::is_lt(result)) {std::cout << "is_lt less" << std::endl;}
    if (std::is_gt(result)) {std::cout << "is_gt greater" << std::endl;}
    if (std::is_eq(result)) {std::cout << "is_eq equal" << std::endl;}

    std::cout << addNumbers(1, 2) << std::endl;

    func();
    return 0;
}
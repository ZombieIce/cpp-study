#include <iostream>
#include <memory>

void reference(int& v) {
    std::cout << " lvalue" << std::endl;
}

void reference(int&& v) {
    std::cout << " rvalue" << std::endl;
}

template <typename T>
void pass(T&& v) {
    std::cout << " 普通参数:";
    reference(v); // 始终调用 reference(int&)
    std::cout << " std::move 传参:";
    reference(std::move(v));
    std::cout << " std::forward 传参:";
    reference(std::forward<T>(v));
    std::cout << " static_cast<T&&> 传参:";
    reference(static_cast<T>(v));
}

int main(int argc, const char** argv) {
    std::cout << " rvalue pass:" << std::endl;
    pass(1);
    std::cout << "==============" << std::endl;
    std::cout << " lvalue pass:" << std::endl;
    int l = 1;
    pass(l);

    return 0;
}
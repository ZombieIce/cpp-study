#include <functional>
#include <iostream>

using foo = void(int);
void functional(foo f) {
    f(1);
}

int foo1(int para) {
    return para;
}

int main(int argc, const char** argv) {
    auto f = [](int value) {
        std::cout << value << std::endl;
    };
    functional(f); // 传递闭包对象，隐式转换为 foo* 类型的函数指针值
    f(1); // lambda 表达式

    std::function<int(int)>func = foo1;
    int important = 10;
    std::function<int(int)> func2 = [&](int value)->int {
        return 1+value+important;
    };

    std::cout << func(10) << std::endl;
    std::cout << func2(10) << std::endl;
    return 0;
}
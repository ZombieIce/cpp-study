#include <iostream>
#include <memory>
#include <utility>

// 值捕获 与参数传值类似，值捕获的前提是变量可以拷贝，不同之处则在于，被捕获的变量在Lambda表达式被创建时拷贝，而非调用时才拷贝
void lambda_value_capture() {
    int value = 1;
    auto copy_value = [value] {
        return value;
    };
    value = 100;
    auto stored_value = copy_value();
    std::cout << "stored_value = " << stored_value << std::endl;
    // stored_value == 1，而value == 100. 因为 copy_value 在创建时就保存了一份value的拷贝
}


// 引用捕获 与引用传参类似，引用捕获保存的是引用，值会发生变化
void lambda_reference_capture() {
    int value = 1;
    auto copy_value = [&value] {
        return value;
    };
    value = 100;
    auto stored_value = copy_value();
    std::cout << "stored_value = " << stored_value << std::endl;
    // copy_value 保存的是引用
}

void lambda_expression_capture() {
    auto important = std::make_unique<int>(1);
    auto add = [v1 = 1, v2 = std::move(important)](int x, int y) -> int {
        return x + y + v1 + (*v2);
    };
    std::cout << add(3, 4) << std::endl;
}

auto add = [](auto x, auto y) {
    return x + y;
};


int main(int argc, const char** argv) {
    lambda_value_capture();
    lambda_reference_capture();
    lambda_expression_capture();
    return 0;
}
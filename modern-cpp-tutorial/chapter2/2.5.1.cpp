#include <initializer_list>
#include <iostream>

template<typename T0>
void printf1(T0 value) {
    std::cout << value << std::endl;
}

template<typename T, typename... Ts>
void printf1(T value, Ts... args) {
    std::cout << value << std::endl;
    printf1(args...);
}

template<typename T0, typename... T>
void printf2(T0 t0, T... t) {
    std::cout << t0 << std::endl;
    if constexpr (sizeof...(t) > 0) printf2(t...);
}

template<typename T, typename... Ts>
auto printf3(T value, Ts... args) {
    std::cout << value << std::endl;
    (void) std::initializer_list<T>{([&args]{
        std::cout << args << std::endl;
    }(), value)...};
}

template<typename T, int BufSize>
class buffer_t {
public:
    T& alloc();
    void free(T& item);
private:
    T data[BufSize];
};

template<auto value> void foo() {
    std::cout << value << std::endl;
    return;
}

int main(int argc, const char** argv) {
    printf1(1, 2, "123", 1.0);
    foo<10>();
    return 0;
}
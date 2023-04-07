#include <type_traits>

int main(int argc, const char** argv) {
    const char (&left)[6] = "01234";
    static_assert(std::is_same<decltype("01234"), const char(&)[6]>::value, "");
    return 0;
}
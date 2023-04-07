#include <algorithm>
#include <iostream>
#include <string>

void reference(std::string& str) {
    std::cout << " 左值" << std::endl;
}

void reference(std::string&& str) {
    std::cout << " 右值" << std::endl;
}

int main(int argc, const char** argv) {
    std::string lv1 = "string,";
    std::string&& rv1 = std::move(lv1);
    std::cout << rv1 << std::endl;

    const std::string& lv2 = lv1 + lv1;
    std::cout << lv2 << std::endl;

    std::string&& rv2 = lv1 + lv2;
    rv2 += "Test";
    std::cout << rv2 << std::endl;

    reference(rv2);

    return 0;
}
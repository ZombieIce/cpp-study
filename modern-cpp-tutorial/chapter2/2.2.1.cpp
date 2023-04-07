#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, const char** argv) {
    std::vector<int> vec = {1, 2, 3, 4};
    // c++17之前
    const std::vector<int>::iterator itr = std::find(vec.begin(), vec.end(), 2);
    if (itr != vec.end()) {
        *itr = 3;
    }

    // c++17之后
    if (const std::vector<int>::iterator itr = std::find(vec.begin(), vec.end(), 3); itr != vec.end()) {
            *itr = 4;
    }

    for (std::vector<int>::iterator element = vec.begin(); element != vec.end(); ++element) {
        std::cout << *element << std::endl;
    }

    return 0;
}
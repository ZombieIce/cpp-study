#include <array>
#include <iostream>
#include <utility>
#include <optional>
#include <vector>

std::optional<int> getData(bool giveIt) {
    if (giveIt) {
        return 42;
    }
    return {};
}

int main(int argc, const char** argv) {
    std::array<int, 3> arr {9, 8, 7};
    std::cout << "Array size = " << arr.size() << std::endl;
    std::cout << "2nd element = " << arr[1] << std::endl;

    std::vector<int> myVector {11, 22};
    myVector.push_back(33);
    myVector.push_back(44);
    std::cout << "1st element: " << myVector[0] << std::endl;


    std::pair<double, int> myPair {1.23, 5};
    std::cout << myPair.first << " " << myPair.second << std::endl;

    std::optional<int> data1 { getData(true)};
    std::optional<int> data2 { getData(false)};

    std::cout << "data1.has_value = " << data1.has_value() << std::endl;
    std::cout << "data1.value = " << *data1 << std::endl;
    if (data2) {
        std::cout << "data2 has a value." << std::endl; 
    }

    return 0;
}

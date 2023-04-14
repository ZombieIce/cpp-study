#include <iostream>
#include <vector>

struct OddsAndEvens { std::vector<int> odds, evens;};

OddsAndEvens seperateOddsAndEvens(const std::vector<int>& arr) {
    std::vector<int> odds, evens;
    for (int i : arr) {
        if (i % 2 == 1)
        {
            odds.push_back(i);
        } else {
            evens.push_back(i);
        }
    }
    return OddsAndEvens{ .odds = odds, .evens = evens};
}

int main(int argc, const char** argv) {

    std::vector<int> vectorSplit {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto oddsAndEvens { seperateOddsAndEvens(vectorSplit)};
    for (const int& i : oddsAndEvens.odds) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    for (const int& i : oddsAndEvens.evens) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}
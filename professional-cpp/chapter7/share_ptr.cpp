#include <cstdio>
#include <iostream>
#include <memory>

void close(FILE* filePtr) {
    if (filePtr == nullptr) { return ;}
    fclose(filePtr);
    std::cout << "FILE closed." << std::endl;
}

int main(int argc, const char** argv) {
    FILE* f { fopen("data.txt", "w")};
    std::shared_ptr<FILE> filePtr { f, close};
    if (filePtr == nullptr) {
        std::cerr << "Error opening file." << std::endl;
    } else {
        std::cout << "File opened." << std::endl;
    }
    return 0;
}
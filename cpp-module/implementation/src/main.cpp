import speech;
#include <iostream>
#include <cstdlib>

int main(int argc, char** argv)
{
    if (std::rand() % 2 ) {
        std::cout << get_phrase_en() << std::endl;
    } else {
        std::cout << get_phrase_es() << std::endl;
    }
    return 0;
}

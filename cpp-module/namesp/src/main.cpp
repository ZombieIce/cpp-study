#include <iostream>
import myModule;

int main(int argc, char** argv)
{
    std::cout << test_func::get_url() << std::endl;
    return 0;
}

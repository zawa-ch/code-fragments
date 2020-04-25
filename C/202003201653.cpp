#include <iostream>

int main(int argc, char const *argv[])
{
    std::cout << "Hello, world" << std::endl;
    std::cout << std::cout.tellp() << std::endl;
    std::cout << std::cin.tellg() << std::endl;
    return 0;
}

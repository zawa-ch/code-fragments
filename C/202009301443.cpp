#include <iostream>
#include <limits>

class None {};

std::ostream& operator<<(std::ostream& stream, const None& value) { return stream; }

int main(int argc, char const *argv[])
{
    std::cout << std::numeric_limits<None>::min() << std::endl; 
    return 0;
}

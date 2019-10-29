#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "BlumBlumShub.hpp"
#include "RandomInteger.hpp"
#include "RandomFraction.hpp"
#include "RandomGaussian.hpp"

int main(int argc, char const *argv[])
{
	std::time_t now = std::time(NULL);
	BlumBlumShub bbs = BlumBlumShub(now);
	RandomInteger rint = RandomInteger(bbs);
	RandomGaussian rand = RandomGaussian(rint, 0.0, 1000.0);
	for (int i = 0; i < 10; i++)
	{
		std::cout << rand.Generate() << std::endl;
	}
	return 0;
}

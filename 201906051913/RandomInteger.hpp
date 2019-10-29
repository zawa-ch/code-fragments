#ifndef RandomInteger_hpp
#define RandomInteger_hpp 1
#include <cstdint>
#include "IRandom.hpp"

class RandomInteger : public IRandomInteger
{
private:
	IRandom& Generator;
	uint32_t Value;
public:
	RandomInteger(IRandom& generator) : Generator(generator), Value(0) {}
	~RandomInteger() {}
	uint32_t GetCurrentValue() { return Value; }
	uint32_t Generate()
	{
		uint32_t Result = 0;
		for (std::size_t i = 0; i < sizeof(uint32_t) * 8; i++)
		{
			// generate, xor bond
			Result ^= Generator.Generate();
			// Rotate
			Result = (Result << 1) | (Result >> (sizeof(uint32_t) * 8 - 1));
		}
		Value = Result;
		return Result;
	}
};

#endif

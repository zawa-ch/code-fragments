#ifndef RandomGaussian_hpp
#define RandomGaussian_hpp 1
#include "IRandom.hpp"
#include <cmath>

class RandomGaussian : public IRandomFloatingPoint
{
private:
    IRandomInteger& gen;
    double Value;
    double Mean;
    double Variance;
public:
    RandomGaussian(IRandomInteger& gen) : gen(gen), Mean(0.0), Variance(1.0) {}
    RandomGaussian(IRandomInteger& gen, double mean, double variance) : gen(gen), Mean(mean), Variance(variance) {}
    ~RandomGaussian() {}

    double GetCurrentValue(void) { return Value; }
    double Generate(void)
    {
        int32_t IVal;
        do
        {
            IVal = int32_t(gen.Generate());
        } while (IVal == INT32_MIN);
        double Result = double(IVal) / 0x80000000UL;
        Result = (0.0 <= Result)?(Result):(-Result);
        Result = Mean + std::sqrt(-2.0 * Variance * std::log(Result)) * ((0 <= IVal)?(1.0):(-1.0));
        Value = Result;
        return Value;
    }
};

#endif

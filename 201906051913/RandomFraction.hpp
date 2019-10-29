#ifndef RandomFraction_hpp
#define RandomFraction_hpp 1
#include "IRandom.hpp"
#include <cmath>

class RandomFraction : public IRandomFloatingPoint, public IRanged<double>
{
private:
    IRandomInteger& gen;
    double Value;
public:
    RandomFraction(IRandomInteger& gen) : gen(gen) {}
    ~RandomFraction() {}

    double GetCurrentValue(void) { return Value; }
    double Generate(void)
    {
        uint32_t IVal = uint32_t(gen.Generate());
        double Result = double(IVal) / UINT32_MAX;
        Value = Result;
        return Value;
    }

    double GetMax(void) { return 1.0; }
    double GetMin(void) { return 0.0; }
};


#endif

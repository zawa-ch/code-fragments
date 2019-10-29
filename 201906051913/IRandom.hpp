#ifndef IRandom_hpp
#define IRandom_hpp 1
#include <cstdint>

template<class T> class IRanged
{
private:
	/* data */
public:
	virtual T GetMin(void) = 0;
	virtual T GetMax(void) = 0;
};

///	乱数ジェネレータインターフェース
///	乱数を生成するためのメソッドを提供します。
template<class T = uint32_t> class IRandom
{
public:
	///	現在の生成されている値を取得します。
	virtual T GetCurrentValue(void) = 0;
	///	次の乱数を生成します。
	virtual T Generate(void) = 0;
};

class IRangedRandom : public IRandom<uint32_t>, public IRanged<uint32_t> { };

class IRandomInteger : public IRandom<uint32_t> { };

class IRandomFloatingPoint : IRandom<double> { };

#endif

#ifndef BlumBlumShub_hpp
#define BlumBlumShub_hpp 1
#include <cstdint>
#include <climits>
#include "IRandom.hpp"

///	Blum-Blum-Shubアルゴリズムを使用した乱数ジェネレータの機能を提供します。
class BlumBlumShub : public IRangedRandom
{
private:
	uint32_t value;

public:
	///	Blum-Blum-Shubアルゴリズム(p1=839,p2=5119139)を使用した乱数ジェネレータを指定したseed値で生成します。
	///	@params
	///	[in]	seed	乱数を生成する際の種となる数値。
	BlumBlumShub(uint32_t seed) : value(seed) {}

	virtual ~BlumBlumShub() {}

	///	アルゴリズムで使用する、2個の素数のひとつ目。
	static const uint32_t p1 = 839;
	///	アルゴリズムで使用する、2個の素数のふたつ目。
	static const uint32_t p2 = 5119139;
	///	アルゴリズムで使用する、2個の素数の積。
	static const uint32_t M = p1 * p2;

	///	現在の生成されている値を取得します。
	///	@return	最後に生成された乱数の値が返ります。
	uint32_t GetCurrentValue(void) { return value; }

	///	次の乱数を生成します。
	///	@return	生成された乱数が返ります。
	uint32_t Generate(void)
	{
		uint64_t Pdc = uint64_t(value) * value;
		value = uint32_t(Pdc % M);
		return value;
	}

	///	このジェネレータで生成可能な最小の数値を取得します。
	///	@return	このジェネレータで生成可能な最大の数値が返ります。
	uint32_t GetMin(void) { return 0; }

	///	このジェネレータで生成可能な最大の数値を取得します。
	///	@return	このジェネレータで生成可能な最大の数値が返ります。
	uint32_t GetMax(void) { return M - 1; }
};

#endif

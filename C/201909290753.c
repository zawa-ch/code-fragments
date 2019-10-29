#include <stdio.h>

typedef unsigned int uint;
typedef _Bool bool;

uint Leaps(uint year);

int main(int argc, char const *argv[])
{
    for (size_t i = 0; i <= 400; i++)
    {
        printf("%lu: %lu(%u)\r\n", i, 365 * i + Leaps(i), Leaps(i));
    }
    
    return 0;
}

bool IsLeapYear(uint Year)
{
	return (Year%400 == 0) || ((Year%4 == 0) && !(Year%100 == 0));
}

uint Leaps(uint years)
{
    uint leaps = (years / 400) - (years / 100) + (years / 4) + (((0 < years) && (!IsLeapYear(years))) ? 1 : 0);	///< うるう年発生日数の計算バッファ。
    return leaps;
}

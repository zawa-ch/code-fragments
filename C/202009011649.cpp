#include <iostream>
#include <limits>

int main(int argc, char const *argv[])
{
	// 明らかにオーバーフローを起こす値キャストの確認

	// 3E113をint型(max:2147483647)に変換
	const double value1 = 3.0e+113;
	int castvalue1 = int(value1);
	std::cout << value1 << " --int cast-> " << castvalue1 << std::endl;

	// Quiet NaN (無効な値)をint型に変換
	const double value2 = std::numeric_limits<double>::quiet_NaN();
	int castvalue2 = int(value2);
	std::cout << value2 << " --int cast-> " << castvalue2 << std::endl;
	return 0;
}

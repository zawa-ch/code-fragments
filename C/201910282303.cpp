#include <iostream>
#include <chrono>
#include <cassert>

typedef float (*factory_func)(int i);

float factory(int i);
float simple_sum(factory_func func, int start, int end);
float compensated_sum(factory_func func, int start, int end);

int main(int argc, char const *argv[])
{
	const uint stage = 100000000;	///< sumの繰り返し回数
	const float answer = 0.01f * stage;	///< 計算の正答
	float result;	///< 計算結果格納用変数
	std::chrono::high_resolution_clock::time_point starttime;	///< 計算開始時刻
	std::chrono::high_resolution_clock::duration elapsed;	///< 計算の所要時間

	// 通常のsum関数
	starttime = std::chrono::high_resolution_clock::now();
	result = simple_sum(factory, 0, stage);
	elapsed = std::chrono::high_resolution_clock::now() - starttime;
	std::cout << "elapsed: " << (double(elapsed.count())*std::chrono::high_resolution_clock::period::num/std::chrono::high_resolution_clock::period::den*1000000) << "us" << std::endl;
	std::cout << "simple sum = " << result << std::endl;
	std::cout << "error = " << (result - answer) << " (" << ((result - answer) / answer * 100) << "%)" << std::endl;

	// 誤差補償付きsum関数
	starttime = std::chrono::high_resolution_clock::now();
	result = compensated_sum(factory, 0, stage);
	elapsed = std::chrono::high_resolution_clock::now() - starttime;
	std::cout << "elapsed: " << (double(elapsed.count())*std::chrono::high_resolution_clock::period::num/std::chrono::high_resolution_clock::period::den*1000000) << "us" << std::endl;
	std::cout << "compensated sum = " << result << std::endl;
	std::cout << "error = " << (result - answer) << " (" << ((result - answer) / answer * 100) << "%)" << std::endl;

	return 0;
}

///	sum用数値生成関数
///	常に0.01を返します。
float factory(int i)
{
	return 0.01f;
}

///	単純なsum関数
///	funcで渡された関数にstartからendで指定された範囲の整数を昇順に渡し、結果の合計を算出します。
float simple_sum(factory_func func, int start, int end)
{
	assert(func != NULL);
	float sum = 0.0f;
	for(int i = start; i < end; i++)
	{
		float value = func(i);
		sum += value;
	}
	return sum;
}

///	誤差補償付きsum関数
///	funcで渡された関数にstartからendで指定された範囲の整数を昇順に渡し、結果の合計を算出します。
///	こちらは誤差を算出しその補償を行うため高精度ですが計算コストは高いです。
float compensated_sum(factory_func func, int start, int end)
{
	assert(func != NULL);
	float sum = 0.0f;
	float c = 0.0f;
	for(int i = start; i < end; i++)
	{
		float value = func(i) - c;
		float bef = sum;
		sum += value;
		c = (sum - bef) - value;	// カハンの加算アルゴリズムによる補償
	}
	return sum;
}

#include <stdio.h>

int main(int argc, char const *argv[])
{
	// 端数処理の確認
	int a = 3;
	int b = 2;
	// 3 / 2 -> 1 (mod: 1)
	printf("3 / 2 = %d\n", a / b);
	return 0;
}

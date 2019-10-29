//sumcalc1 by zawa-ch.
//1から指定した数値まで足しつづけるプログラム(rev.1)

#include<stdio.h>

int main(void) {
	int i;
	int va, sum=0;

	puts("整数を入力してください。\n"
		"１からその数値まで足し続けた数値を返します。");
	printf("整数 : ");
	scanf("%d", &va);	//実は、負の値を入力されたときの処理がないため、不完全(実際に入力すると、結果が0になる)

	for (i = 1; i <= va; i++)
		sum += i;

	printf("結果は%dです。\nまた、n(1+n)/2で計算した結果は%dです。\n", sum, va * (1 + va) / 2);

	return 0;
}

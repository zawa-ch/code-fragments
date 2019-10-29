//sumcalc2 by zawa-ch.
//1から指定した数値まで足しつづけるプログラム(rev.2)

#include<stdio.h>

int main(void) {
	int i;
	int va, sum=0;

	puts("整数を入力してください。\n"
		"１からその数値まで足し続けた数値を返します。");
	do {
		printf("整数 : ");
		scanf("%d", &va);
		if (va <= 0)
			puts("\a入力された値が不適切です。\n1以上の整数を入力してください。");
	} while (va <= 0);	//負の値を入力したときの処理を追加(0以下の値を入力するともう一度入力を求められる)

	for (i = 1; i <= va; i++)
		sum += i;

	printf("結果は%dです。\nまた、n(1+n)/2で計算した結果は%dです。\n", sum, va * (1 + va) / 2);

	return 0;
}

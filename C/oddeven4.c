//oddeven4 by zawa-ch.
//intが小数点以下切り捨てであることを利用した判別方法

#include<stdio.h>

int main(void) {
	int va;	//初期化処理

	puts("整数を入力してください。\n偶数・奇数を判別します。");	//整数の入力を求める
	printf("整数 : ");
	scanf("%d", &va);

	if (( (va + 1) / 2) - (va / 2))	//入力された数値に1を足してから2で割ったものとそのまま2で割ったものを比較
		printf("%dは奇数です。\n", va);
	else
		printf("%dは偶数です。\n", va);

	return 0;
}

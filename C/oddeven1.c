//oddeven1 by zawa-ch.
//入力された値の2で割ったあまりを求め、偶数・奇数を判断する

#include<stdio.h>

int main(void) {
	int va;	//初期化処理

	puts("整数を入力してください。\n偶数・奇数を判別します。");	//整数の入力を求める
	printf("整数 : ");
	scanf("%d", &va);

	if (va % 2)	//2で割ったあまりを求める(1なら奇数、0なら偶数)
		printf("%dは奇数です。\n", va);
	else
		printf("%dは偶数です。\n", va);

	return 0;
}

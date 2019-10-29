//oddeven2 by zawa-ch.
//最初のビットが1か0かを使って偶数・奇数を判断する

#include<stdio.h>

int main(void) {
	int va;	//初期化処理

	puts("整数を入力してください。\n偶数・奇数を判別します。");	//整数の入力を求める
	printf("整数 : ");
	scanf("%d", &va);

	if (va & 1)	//最初のビットが0か1か判断(1なら奇数、0なら偶数)
		printf("%dは奇数です。\n", va);
	else
		printf("%dは偶数です。\n", va);

	return 0;
}

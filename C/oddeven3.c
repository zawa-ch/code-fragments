//oddeven3 by zawa-ch.
//switch文を用いて偶数・奇数を分岐(あまりおすすめしない)

#include<stdio.h>

int main(void) {
	int va;	//初期化処理

	puts("整数を入力してください。\n偶数・奇数を判別します。");	//整数の入力を求める
	printf("整数 : ");
	scanf("%d", &va);

	switch (va % 2) {	//switchで2で割った余りが0か1かを分岐((あれ、見やす...(殴
	case 0:
		printf("%dは偶数です。\n", va);
		break;
	case 1:
		printf("%dは奇数です。\n", va);
		break;
	}

	return 0;
}

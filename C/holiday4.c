//holiday4 by zawa-ch.
//2016年の入力された月の祝日の数を返す(配列変数を使用)

#include<stdio.h>

int main(void) {
	int va;
	int holy[12] = {2, 1, 2, 1, 3, 0, 1, 0, 2, 1, 2, 1};

	puts("1から12までの整数を入力してください。\n2016年のその月の祝日の数を返します。");
	do {
		printf("月 : ");
		scanf("%d", &va);
		if (va <= 0 || va > 12)
			printf("入力された数値 %d は無効です。\n1から12までの整数を入力してください。\n", va);
	} while (va <= 0 || va > 12);

	printf("%d月の祝日の数は %d です。\n", va, holy[va - 1]);

	return 0;
}

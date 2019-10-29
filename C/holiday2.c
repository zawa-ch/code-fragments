//holiday2 by zawa-ch.
//2016年の入力された月の祝日の数を返す(switch文を使用2)

#include<stdio.h>

int main(void) {
	int va;

	puts("1から12までの整数を入力してください。\n2016年のその月の祝日の数を返します。");
	do {
		printf("月 : ");
		scanf("%d", &va);
		if (va <= 0 || va > 12)
			printf("入力された数値 %d は無効です。\n1から12までの整数を入力してください。\n", va);
	} while (va <= 0 || va > 12);

	switch (va) {
	case 1:
		puts("1月の祝日の数は二つです。");
		break;
	case 2:
		puts("2月の祝日の数は一つです。");
		break;
	case 3:
		puts("3月の祝日の数は二つです。");
		break;
	case 4:
		puts("4月の祝日の数は一つです。");
		break;
	case 5:
		puts("5月の祝日の数は三つです。");
		break;
	case 6:
		puts("6月の祝日はありません。");
		break;
	case 7:
		puts("7月の祝日の数は一つです。");
		break;
	case 8:
		puts("8月の祝日はありません。");
		break;
	case 9:
		puts("9月の祝日の数は二つです。");
		break;
	case 10:
		puts("10月の祝日の数は一つです。");
		break;
	case 11:
		puts("11月の祝日の数は二つです。");
		break;
	case 12:
		puts("12月の祝日の数は一つです。");
		break;
	}

	return 0;
}

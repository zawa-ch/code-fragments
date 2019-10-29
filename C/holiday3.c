//holiday3 by zawa-ch.
//2016年の入力された月の祝日の数を返す(switch文を使用3)

#include<stdio.h>

int main(void) {
	int va, holy;

	puts("1から12までの整数を入力してください。\n2016年のその月の祝日の数を返します。");
	do {
		printf("月 : ");
		scanf("%d", &va);
		if (va <= 0 || va > 12)
			printf("入力された数値 %d は無効です。\n1から12までの整数を入力してください。\n", va);
	} while (va <= 0 || va > 12);

	switch (va) {
	case 1:
		holy = 2;
		break;
	case 2:
		holy = 1;
		break;
	case 3:
		holy = 2;
		break;
	case 4:
		holy = 1;
		break;
	case 5:
		holy = 3;
		break;
	case 6:
		holy = 0;
		break;
	case 7:
		holy = 1;
		break;
	case 8:
		holy = 0;
		break;
	case 9:
		holy = 2;
		break;
	case 10:
		holy = 1;
		break;
	case 11:
		holy = 2;
		break;
	case 12:
		holy = 1;
		break;
	}

	printf("%d月の祝日の数は %d です。\n", va, holy);

	return 0;
}

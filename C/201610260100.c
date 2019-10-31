//支払額から最低必要な硬貨の枚数を計算するプログラム
#include <stdio.h>
#define ACCOUNTING_MAX 1000
const unsigned int units[] ={500, 100, 50, 10, 5, 1};
#define unit_count (sizeof(units)/sizeof(units[0]))
#define Unit_Count_MAX 10
//状況に応じて変化させる定数はなるべく上に持っていく
//defineを用いることでマジックナンバー(値の意味が不明瞭な数値)をなくす
int main(void)
{	//インデンテーションを行うことで視認性が格段に向上する
	unsigned int i, accounting, buffer;
		//変数名は意味を持つものにすると良い
		//また本来プログラム中で意味の変わる変数は宣言しないほうが良い
		//Cにおいて変数宣言は一番最初でしかできない
	unsigned int count[Unit_Count_MAX];
		//Cでは宣言する配列の大きさはコンパイル時に決定されている必要がある
		//(動的に変化させる方法もあるが、ポインタの概念を用いるうえに~~面倒~~複雑なため今回は使用しない)
	puts("支払額から最低必要な硬貨の枚数を計算します");
	printf("支払額を入力してください(1 ... %d)\n", ACCOUNTING_MAX-1);
	do	//gotoはdo-whileで代用できる
	{
		printf("> ");
		scanf("%u", &accounting);
		if(accounting<=0 || accounting>=ACCOUNTING_MAX)
			printf("%uは無効な値です。1 ... %dの範囲内で入力してください\n", accounting, ACCOUNTING_MAX-1);
	} while(accounting<=0 || accounting>=ACCOUNTING_MAX);

	printf("支払金額: %u", accounting);

	for (i= 0; i<unit_count; ++i)
	{
		if(units[i]==0)
		{
			//所々に例外処理が入っていた点については◎
			printf("使用する硬貨に問題が見つかりました。\n使用する硬貨の再確認を行ってください。");
			return -1;
		}
		else
		{
			buffer= accounting % units[i];
			count[i]= (accounting - buffer) / units[i];
			accounting= buffer;
		}
		if(accounting==0)
			break;
		//割り切れた段階で処理を切り上げる
	}
	if(accounting==0)
		//割り切れたかどうかの判定(割り切れた場合は0になる)
	{
		puts("支払いに必要な硬貨の枚数");
		buffer= 0;
		for(i=0; i<unit_count; i++)
		{
			printf("%u円玉: %u枚\n", units[i], count[i]);
			buffer+= count[i];
		}
		printf("合計: %u枚", buffer);
		return 0;
	}
	else
	{
		puts("支払金額に対し、指定された効果の種類では割り切れませんでした。\n使用する硬貨の再確認を行ってください。");
		return -1;
	}
}
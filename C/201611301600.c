//stdio.hは必ずincludeすること!これがないと基本始まりません
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define MAIN_MODE_COUNT (sizeof(SelectorTableText)/sizeof(SelectorTableText[0]))
#define L2_Input_Max 0xFFFF
	// 課題2で使用する入力の最大値
#define ACCOUNTING_MAX 1000-1
	// 課題3で使用する入力の最大値
#define L3_UNIT_COUNT (sizeof(units)/sizeof(units[0]))
	// units[]配列の要素数
#define L3_COUNT_SIZE 10
	// 課題3で使用する配列の要素数
const char *SelectorTableText[] ={"終了", "課題1 BMI計算", "課題2 10進->2進変換", "課題3 硬貨枚数計算"};
	// プログラム選択に使用するテーブル
const double BMITable[] ={18.5, 25.0, 30.0, 35.0, 40.0};
	// BMIからの体型判定に用いるテーブル
const char *BMIText[] ={"低体重", "標準体型", "肥満(1度)", "肥満(2度)", "肥満(3度)", "肥満(4度)"};
	// BMIの体型判定結果
const unsigned int units[] ={500, 100, 50, 10, 5, 1};
	// 課題3で使用する硬貨のテーブル

// 関数のプロトタイプ宣言-------
int L1();	//課題1の回答
int L2();	//課題2の回答
int L3();	//課題3の回答
// -----------------------------

// アプリケーションのメインエントリ
int main(int argc, char const *argv[])
{
	int sel =0, cur;
		//sel: カーソル値
		//cur: 入力キーバッファ

	for(;;){
		//画面クリア
		system("cls");
		//説明を表示
		puts("- 回路班 課題プログラム\n- 上下キーおよび0 ... 3で選択、Returnで決定");
		do {
			//表示の更新
			printf("%1d.%-20s\r", sel, SelectorTableText[sel]);
			//入力待ち
			cur= 0;
			cur= getch();
			if(kbhit()) getch();
			//入力を処理
			if(GetKeyState(VK_UP)&0x8000)	//上キー入力時の処理
				cur= sel + 1;
			else if(GetKeyState(VK_DOWN)&0x8000)	//下キー入力時の処理
				cur= sel - 1;
			else if(cur>='0' && cur<='3')	//数字直接入力時の処理
				cur-= '0';
				//入力されたキー情報を数値にするには0の文字コードを差し引けばOK
				//(ASCIIコードベースの場合)
			else
				cur= sel;
			sel= cur;	//カーソルに反映
			if(sel>=MAIN_MODE_COUNT)
				sel= 0;
			if(sel<0)
				sel= MAIN_MODE_COUNT-1;
		} while(!(GetKeyState(VK_RETURN)&0x8000));	//Returnが入力されたら抜ける

		switch(sel)
		{
		case 0:	//0: 終了
			return 0;
		case 1:	//1: BMIプログラム
			system("cls");
			L1();
			break;
		case 2:	//2: 2進数に変換
			system("cls");
			L2();
			break;
		case 3:	//3: 支払い硬貨枚数計算
			system("cls");
			L3();
			break;
		}
		//プログラム動作完了時の処理
		printf("続行するには何かキーを押してください...");
		getch();
	}
}

// 課題1の回答 -----------------
int L1()
{
	int i;
		// インデックス変数
	double height, weight, bmi;
		// 身長・体重・BMI計算結果

	puts("- 身長・体重からボディマスインデックス(BMI)を導出します\n- 身長と体重を入力してください");
	// 入力を求める
	printf("Height[m]> ");	scanf("%lf", &height);
	printf("Weight[kg]> ");	scanf("%lf", &weight);
	// 身長・体重に0以下の値が入力された時の例外処理
	if(height<=0 || weight<=0)
	{
		printf("- 無効な値が入力されました!\n- 0より大きい値を入力してください\n");
		return -1;
	}
	putchar('\n');

	// BMIを計算
	bmi= weight / height / height;
	// テーブルを基に体型を判定
	for(i=0; i<(sizeof(BMITable) / sizeof(double)); i++)
	{
		if(bmi<BMITable[i])
			break;
	}
	printf("- あなたのBMIが%.2fと算出されました、%sです\n", bmi, BMIText[i]);
	return 0;
}

// 課題2の回答 -----------------
int L2()
{
	int i;
		// インデックス変数
	int dec;
		// 変換元の10進数

	printf("- 10進数を2進数に変換します\n- 0 ... %dの範囲内の数値を入力してください\n", L2_Input_Max);
	// 入力を求める
	printf("Dec> ");	scanf("%d", &dec);
	// 規定外の値が入力された場合の処理
	if(dec<0 || dec>L2_Input_Max)
	{
		printf("- 無効な値が入力されました!\n- 利用可能な値は0 ... %dの範囲内です\n", L2_Input_Max);
		return -1;
	}
	putchar('\n');

	printf("- %dを2進数に変換すると\n- ", dec);
	for(i=15; i>=0; i--)
	{
		putchar((dec & (1<<i)) ? ('1') : ('0'));
	}
	puts("\n- です");
	return 0;
}

// 課題3の回答 -----------------
int L3()
{
	int i;
		// インデックス変数
	int accounting, calc, buffer;
		// 入力する支払金額, 計算に使用する一時変数
	int count[L3_COUNT_SIZE];
		// 必要なそれぞれの種類の硬貨

	puts("- 入力された値からその額の支払いに最低限必要な硬貨の枚数を計算します");
	printf("- 金額を1 ... %dの範囲内で入力してください\n", ACCOUNTING_MAX);
	// 入力を求める
	printf("accounting> ");	scanf("%d", &accounting);
	// 規定外の値が入力された時の処理
	if(accounting<=0 || accounting>ACCOUNTING_MAX)
	{
		printf("- 無効な値が入力されました!\n- 1 ... %dの範囲内で入力してください\n", accounting, ACCOUNTING_MAX);
		return -1;
	}

	// 枚数の計算
	calc= accounting;
	for (i= 0; i<L3_UNIT_COUNT; ++i)
	{
		if(units[i]<=0)
		{
			// 硬貨のテーブルの値がおかしい時の処理
			printf("- 使用する硬貨に問題が見つかりました。\n- 使用する硬貨の再確認を行ってください。\n");
			return -2;
		}
		else
		{
			buffer= calc % units[i];
			count[i]= (calc - buffer) / units[i];
			calc= buffer;
		}
		// 割り切れた段階で処理を切り上げ
		if(calc==0)
			break;
	}
	if(calc==0)
	{
		// 割り切れた場合結果を表示
		printf("- %d円の支払いに必要な硬貨の枚数\n", accounting);
		buffer= 0;
		for(i=0; i<L3_UNIT_COUNT; i++)
		{
			printf("- %u円玉: %d枚\n", units[i], count[i]);
			buffer+= count[i];
		}
		printf("- 合計%d枚の硬貨が必要になります\n", buffer);
		return 0;
	}
	else
	{
		// 割り切れない場合はその旨を表示
		puts("- 支払金額に対し、指定された硬貨の種類では割り切れませんでした\n- 使用する硬貨の再確認を行ってください");
		return -2;
	}
}

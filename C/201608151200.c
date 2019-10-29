#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

//構造体宣言
typedef struct
{
	char *name;
	int position =0;
	int info[12] ={0};
} Player;
typedef struct
{
	int
		seed,
		size
	;
	double rate_event[3];
	char
		data[65536];
} Map;

//プロトタイプ宣言
int isExistFile(const char filename[FILENAME_MAX]);/*ファイルの存在を確認
	ファイルの存在を確認,読み込みができるか確認します
	読み込みができれば1,できなければ0が返ってきます
*/
int rourette(int max, unsigned int seed);/*ルーレット
	エンターキーが押されるまで0<->(max-1)までのルーレットを行います
	エンターキーが押された時の数値が返ってきます
	乱数生成のシード値を必ず指定してください
*/

//メイン関数
int main(int argc, char const *argv[])
{
	int i, j;
		//インデックス変数[8]
	int member =0;
	Player *Player_data[16];
	Map Map_data;

	puts("");
	return 0;
}

//サブ関数
int isExistFile(const char filename[FILENAME_MAX])
{
	int rtb =0;
	FILE *fp;
	if((fp= fopen(filename, "r")) != NULL)
	{
		rtb= 1;
		fclose(fp);
	} else {
		rtb= 0;
	}
	return rtb;
}

int rourette(unsigned int max, unsigned int seed)
{
	unsigned int rtb;
	unsigned char key =0;
	srand(seed);
	while(key== '\n'){
		rtb=rand();
		printf("Enterキーでストップします: %-12d\r", rtb);
		if(kbhit())
			key=getch();
	}
	printf("ルーレット結果: %-12d\n", rtb);
	return rtb%max;
}
#include <stdio.h>

#define C1

#ifdef C1
int main(int argc, char const *argv[])
{
	char* str;

	puts("文字列を入力してください");
	scanf("%s", str);

	printf("入力された文字列は、「%s」です。\n", str);

	return 0;
}
#endif

#ifdef C2
int main(int argc, char const *argv[])
{
	char* str[] ={"abc", "defg", "hijklmn"};
	int i, n;

	n= sizeof(str)/sizeof(str[0]);

	for (i= 0; i<n; ++i){
		printf("%d %s\n", i, str[i]);
	}
	return 0;
}
#endif

#ifdef C3
#include <stdio.h>

typedef struct
{
	double a, b, c;
} keisu;

int main(int argc, char const *argv[])
{
	int i;
	double x, y;
	keisu data;

	puts("係数a,b,cを入力してください。");
	scanf("%lf%lf%lf", &data.a, &data.b, &data.c);

	for (i= 0; i<100; ++i){
		x= i*0.1;
		y= data.a*x*x - data.b*x + data.c;
		printf("%f %f\n", x, y);
	}
	return 0;
}
#endif

#ifdef C4
int main(int argc, char const *argv[])
{
	FILE *fpin, *fpout;
	char fin[FILENAME_MAX];
	double x, y;

	printf("ファイル名を指定してください。(%d文字以内)\n> ", FILENAME_MAX);
	scanf("%s", fin);

	if((fpin= fopen(fin, "r")) != NULL){
		fpout= fopen("data_modify.txt", "w");
		while(fscanf(fpin, "%lf%lf", &x, &y)==2)
			fprintf(fpout, "%f, %f\n", x*0.001, y*y);
		fclose(fpout);
		fclose(fpin);
	} else {
		printf("ファイルを開けませんでした。\n");
	}

	return 0;
}
#endif
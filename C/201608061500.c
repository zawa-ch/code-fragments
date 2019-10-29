#include <stdio.h>
main()
{
	char filename[FILENAME_MAX];
	FILE *fp;
	printf("ファイル名を入力してください.\n!ここで指定されたファイルの内容が消去されます!\n> ");
	scanf("%s", filename);

	fp= fopen(filename, "w");
	if(fp)
	{
		printf("処理が完了しました.\n");
		fclose(fp);
	}
	else
		printf("処理に失敗しました.\n");
	return 0;
}
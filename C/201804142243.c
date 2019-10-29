#include <stdio.h>

int main()
{
	char str[256];
	int iBuf = 0;
	int iIndex = 0;
	printf("> ");
	scanf("%s", str);
	printf("> ");
	scanf("%d", &iBuf);
	if (iBuf != 0)
	{
		while(str[iIndex]!='\0')
		{
			if (str[iIndex] >= '0' && str[iIndex] <= '9')
				putchar((str[iIndex]+iBuf)>'9'?(((str[iIndex]+iBuf-'0')%(10))+'0'):(str[iIndex]+iBuf));
			else if (str[iIndex] >= 'A' && str[iIndex] <= 'Z')
				putchar((str[iIndex]+iBuf)>'Z'?(((str[iIndex]+iBuf-'A')%(26))+'A'):(str[iIndex]+iBuf));
			else if (str[iIndex] >= 'a' && str[iIndex] <= 'z')
				putchar((str[iIndex]+iBuf)>'z'?(((str[iIndex]+iBuf-'a')%(26))+'a'):(str[iIndex]+iBuf));
			else
				putchar(str[iIndex]);
			iIndex++;
		}
		printf("\r\n");
	}
	else
	{
		for(iBuf = 0; iBuf < 26; iBuf++)
		{
			iIndex = 0;
			while(str[iIndex]!='\0')
			{
				if (str[iIndex] >= '0' && str[iIndex] <= '9')
					putchar((str[iIndex]+iBuf)>'9'?(((str[iIndex]+iBuf-'0')%(10))+'0'):(str[iIndex]+iBuf));
				else if (str[iIndex] >= 'A' && str[iIndex] <= 'Z')
					putchar((str[iIndex]+iBuf)>'Z'?(((str[iIndex]+iBuf-'A')%(26))+'A'):(str[iIndex]+iBuf));
				else if (str[iIndex] >= 'a' && str[iIndex] <= 'z')
					putchar((str[iIndex]+iBuf)>'z'?(((str[iIndex]+iBuf-'a')%(26))+'a'):(str[iIndex]+iBuf));
				else
					putchar(str[iIndex]);
				iIndex++;
			}
			printf("\r\n");
		}
	}
}

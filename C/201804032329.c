#include <stdio.h>
#include <stdlib.h>

#define __DEBUG__ 0

int* placelist;
int depth = 0;

int main(void)
{
	int ivalue;
	fprintf(stdout, "n? : ");
	scanf("%d", &ivalue);
	for (;ivalue > 0; ivalue--)
	{
#if __DEBUG__!=0
		printf("ivalue = %d\r\n", ivalue);
#endif
		placelist = malloc(sizeof(int) * ivalue);
		CombLoop(0, ivalue);
		free(placelist);
	}
	return 0;
}

int CombLoop(int index, int placen)
{
	int i, j;
	unsigned long int n;
	depth++;
	placen--;
	for(i = index; i < 32 - placen; i++)
	{
		placelist[depth - 1] = i;
		if (placen)
		{
			CombLoop(i + 1, placen);
		}
		else
		{
			n = 0;
			for (j = 0; j < depth; j++)
			{
				n |= 1U << placelist[j];
#if __DEBUG__!=0
				printf("%d  ", placelist[j]);
#endif
			}
#if __DEBUG__!=0
			printf("%u(%d / %d)\r\n", n, bitcount(n), depth);
#else
			printf("%u\r\n", n);
#endif
		}
	}
	depth--;
}

int bitcount(unsigned int n)
{
	int i, cnt = 0;
	for (i = 0; i < 32; i++)
	{
		cnt += (n >> i) & 0x01;
	}
	return cnt;
}

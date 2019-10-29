#include <stdio.h>

int main(void)
{
	unsigned int i1, i2, i3;
	for(i3 = 0; i3 < 30; i3++)
	{
		for(i2 = i3 + 1; i2 < 31; i2++)
		{
			for(i1 = i2 + 1; i1 < 32; i1++)
			{
				printf("%u\r\n", ((1U<<i3)|(1U<<i2)|(1U<<i1)));
			}
		}
	}
	return 0;
}

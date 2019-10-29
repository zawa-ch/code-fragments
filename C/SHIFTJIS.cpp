//Code Table of SHIFT-JIS
#include <stdio.h>
int main(void){
	int i, j, k;
	unsigned char c1 =0, c2 =0;
	puts("SHIFT-JIS •¶šƒR[ƒhˆê——");
	printf("  0123456789ABCDEF\n");
	for(i =0x2; i<0xE; ++i)
	{
		if(!(i>=0x8 && i<0xA)){
			c1= i*0x10;
			printf("%02x",c1);
			for(j =0; j<16; j++)
				printf("%1c", c1++);
			putchar('\n');
		}
	}
	putchar('\n');
	printf("    0 1 2 3 4 5 6 7 8 9 A B C D E F\n");
	for(i =0x81; i<0xFD; i++){
		c1= i;
		if(!(i>=0xA0 && i<0xE0)){
			for(j =4; j<16; j++){
				c2= j*0x10;
				printf("%02x%02x", c1, c2);
				for(k =0; k<16; k++)
					printf("%c%1c", c1, c2++);
				putchar('\n');
			}
		}
	}
	return 0;
}
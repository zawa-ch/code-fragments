#include <stdio.h>
int main(void){
	char* p;
	p= "Hello, world!";
	printf("%s\n", p);
	printf("0x%p\n", p);
	return 0;
}
#include<stdio.h>
int main(void){
	int n1, n2;
	char *a[] ={"12", "345", "6789", "87"};
	printf("%d, %d\n", sizeof(char*), sizeof(a));
	return 0;
}
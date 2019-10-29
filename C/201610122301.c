#include <stdio.h>
#include <math.h>
int main(){
	FILE *fp;
	double x=1.0;
	double L;
	double R;
	fp= fopen("output.csv", "w");
	printf(" x          |  L          |  R          \n");
	fprintf(fp, "x\tL\tR\n");
	for(; x!=0.0; )
	{
		L= (2*pow(sin(x/2), 2));
		R= 1-cos(x);
		printf("%e| %e| %e\n", x, L, R);
		fprintf(fp, "%e\t%e\t%e\n", x, L, R);
		x/= 10.0;
	}
	return 0;
}
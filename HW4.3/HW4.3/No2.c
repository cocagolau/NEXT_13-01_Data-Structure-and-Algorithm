#include <time.h>
#include <stdio.h>

int main(void)
{
	clock_t t = clock();
	double sec;

	long num, sum=0;
	int i;
	printf("Input : ");
	scanf("%d", &num);
	
	t= clock();
	for(i=1; i<=num; i++){
		sum = sum+i;
	}

	t = clock() - t;
	sec = (double)t / CLOCKS_PER_SEC;
	printf("1부터 %d까지 합 : %d\n", num, sum);
	printf("%f 초 소요됨 \n", sec);
}
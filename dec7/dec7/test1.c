#include<stdio.h>

int fi(int n)
{
	int temp;

	if(n==0 || n==1)
		return 1;
	else
		return fi(n-1)+fi(n-2);
}

int main(void)
{
	int num, result;

	printf("input : ");
	scanf("%d", &num);
	result = fi(num);

	printf("%d \n", result);
	return 0;
}
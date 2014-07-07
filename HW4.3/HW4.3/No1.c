#include <stdio.h>

void sum(int from, int to, int* result);

int main(void)
{
	int from, to, fake_result;

	printf("Input : ");
	scanf("%d %d", &from, &to);

	sum(from, to, &fake_result);
	printf("Output : %d\n", fake_result);

	return 0;
}

void sum(int from, int to, int* result)
{
	int sum=0, i;

	for(i=from; i<=to; i++){
		sum = sum + i;
	}

	*result = sum;
}
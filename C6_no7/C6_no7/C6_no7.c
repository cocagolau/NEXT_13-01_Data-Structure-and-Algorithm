#include<stdio.h>
int main(void)
{
	int r;
	float result1, result2;

	printf("원의 반지름을 입력하세요 : ");
	scanf("%d", &r);

	result1 = 3.14*r*r;
	result2 = 3.14*2*r;

	printf("원의 면적 : %f \n", result1);
	printf("원의 둘레 : %f \n", result2);
	return 0;
}

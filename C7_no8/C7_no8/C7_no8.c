#include<stdio.h>
int main(void)
{
	int num, sum=0, count=0;
	
	do
	{
		count ++;
		printf("%d번째 정수를 입력하세요 : ", count);
		scanf("%d", &num);
		sum += num;
	}while(num);

	printf("총 합계 : %d,  %d번 입력\n", sum, count-1);
	return 0;
}
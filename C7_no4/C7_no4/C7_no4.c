#include<stdio.h>
int main(void)
{
	int i, num;
	printf("숫자를 입력하세요 " );
	scanf("%d", &num);

	for(i=0; i<10; i++)
		printf("5 * %d = %d입니다.\n", i, 5*i);
	return 0;
}
#include<stdio.h>
int main(void)
{
	int num, sum=0, count=0;
	
	do
	{
		count ++;
		printf("%d��° ������ �Է��ϼ��� : ", count);
		scanf("%d", &num);
		sum += num;
	}while(num);

	printf("�� �հ� : %d,  %d�� �Է�\n", sum, count-1);
	return 0;
}
#include<stdio.h>
int main(void)
{
	int r;
	float result1, result2;

	printf("���� �������� �Է��ϼ��� : ");
	scanf("%d", &r);

	result1 = 3.14*r*r;
	result2 = 3.14*2*r;

	printf("���� ���� : %f \n", result1);
	printf("���� �ѷ� : %f \n", result2);
	return 0;
}

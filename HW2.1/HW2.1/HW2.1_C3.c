/*
     �ۼ��� : 13.03.12 AM 09:40
     �ۼ��� : ������
     ������ : HW#2.1.C3
	 ���α׷� �Ұ�: 1�̻� ������ �Է½� �Էµ� �������� 1���� ���� ���ϴ� ���α׷�
*/

#include<stdio.h>

int Sum(int i);

int main(void)
{
	int num, result;

	printf("input your number = ");
	scanf("%d", &num);

	result = Sum(num);
	printf("1���� %d������ �� = %d \n", num, result);

	return 0;
}

int Sum(int i)
{
	int result;

	if(i<=1)
		return i;

	result = i + Sum(i-1);

	return result;
}
/*
     �ۼ��� : 13.03.12 AM 09:30
     �ۼ��� : ������
     ������ : HW#2.1.C2
	 ���α׷� �Ұ�: �� ������ �Է¹޾� �����ϵ�, 0 0�Է½� ���� �� ����� ���
*/

#include<stdio.h>

int Add(int i, int j);
int Count(void);

int main(void)
{
	int num1, num2, result, count_num;
	int i;

	for(i=0; i<100; i++)
	{
		count_num = Count();

		printf("���� �� ���� �Է��ϼ���(0 0 -> exit) : ");
		scanf("%d %d", &num1, &num2);

		if(num1==0 && num2==0)
		{
			printf("�� ���� �� : %d\n", count_num-1);
			break;
		}

		result = Add(num1, num2);
		printf("���� ��� : %d\n", result);
	}

	return 0;
}

int Add(int i, int j)
{
	int result;
	result = i + j;

	return result;
}

int Count(void)
{
	static int count_num;
	count_num ++;

	return count_num;
}
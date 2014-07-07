/*
	�ۼ��� : 13�� 4�� 7�� ���� 12�� 59��
	�ۼ��� : ������
	���α׷� ���� : ���׽� ��� ���α׷� / ���� �Ǳ������ ����
*/


#include <stdio.h>
#include <stdlib.h>

int getValue(int list[], int list_num, int x_value);

int main(void)
{
	int *list=NULL;
	int list_num;
	int i, x_value, result;

	printf("array_num : ");
	scanf("%d", &list_num);

	printf("X_Value Input : ");
	scanf("%d", &x_value);

	list = (int*) malloc (sizeof(int) * list_num);
	
	printf("Input array : \n");
	for (i=0; i<list_num; i++) {
		scanf("%d", list+i);
	}

	result = getValue(list, list_num, x_value);
	printf("\nOutput : %d \n", result);
	
	free(list);
	list = NULL;

	return 0;
}

int getValue(int list[], int list_num, int x_value)
{
	int i, sum=0, power=1;

	for (i=0; i<list_num; i++) {
		if (i!=0)
			power = power * x_value;
		
		list[i] = list[i] * power;
		sum = sum + list[i];
	}

	return sum;
}
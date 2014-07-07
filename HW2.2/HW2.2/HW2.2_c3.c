/*
     �ۼ��� : 13.03.15 PM 20:00
     �ۼ��� : ������
     ������ : HW#2.2.C3
     ���α׷� �Ұ�: �μ��� �Է¹޾� ��Ģ������ ����ϴ� ���α׷�
*/

#include<stdio.h>
#include<stdlib.h>

void* add(int a, int b);
void* subtract(int a, int b);
void* multiply(int a, int b);
void* divide(int a, int b);

int main(void)
{
	int num1, num2;
	void* ptr=NULL;

	printf("��Ģ������ �� ���� �Է��ϼ��� : ");
	scanf("%d %d", &num1, &num2);

	ptr = add(num1, num2);
	printf("��  �� : %d \n", *(int*)ptr);

	ptr = subtract(num1, num2);
	printf("��  �� : %d \n", *(int*)ptr);

	ptr = multiply(num1, num2);
	printf("��  �� : %d \n", *(int*)ptr);

	ptr = divide(num1, num2);
	printf("������ : %f \n", *(float*)ptr);

	free(ptr);
	ptr=NULL;
	
	return 0;
}

void* add(int a, int b)
{
	int* result = (int*)malloc(sizeof(int));
	*result = a + b;

	return result;
}

void* subtract(int a, int b)
{
	int* result = (int*)malloc(sizeof(int));
	*result = a - b;

	return result;
}

void* multiply(int a, int b)
{
	int* result = (int*)malloc(sizeof(int));
	*result = a * b;

	return result;
}

void* divide(int a, int b)
{
	float* result = (float*)malloc(sizeof(float));
	*result = (float)a / (float)b;

	return result;
}
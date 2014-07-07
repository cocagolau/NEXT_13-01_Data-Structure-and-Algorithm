/*
     작성일 : 13.03.15 PM 20:00
     작성자 : 서동규
     과제명 : HW#2.2.C3
     프로그램 소개: 두수를 입력받아 사칙연산을 계산하는 프로그램
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

	printf("사칙연산할 두 수를 입력하세요 : ");
	scanf("%d %d", &num1, &num2);

	ptr = add(num1, num2);
	printf("덧  셈 : %d \n", *(int*)ptr);

	ptr = subtract(num1, num2);
	printf("뺄  셈 : %d \n", *(int*)ptr);

	ptr = multiply(num1, num2);
	printf("곱  셈 : %d \n", *(int*)ptr);

	ptr = divide(num1, num2);
	printf("나눗셈 : %f \n", *(float*)ptr);

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
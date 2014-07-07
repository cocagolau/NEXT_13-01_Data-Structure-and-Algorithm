/*
     작성일 : 13.03.11 PM 10:20
     작성자 : 서동규
     과제명 : HW#2.1.C1
	 프로그램 소개: 입력된 두 정수의 사칙연산을 구하는 프로그램
*/


#include<stdio.h>

int plus(int i, int j);
int minus(int i, int j);
int multiply(int i, int j);
float divide(int i, int j);

int main(void)
{
	int a,b;
	int result;
	double result2;

	printf("input two numbers : ");
	scanf("%d %d", &a, &b);

	result = plus(a,b);
	printf("a + b = %d \n", result);

	result = minus(a,b);
	printf("a - b = %d \n", result);

	result = multiply(a,b);
	printf("a * b = %d \n", result);

	result2 = divide(a,b);
	printf("a / b = %lf \n", result2);

	return 0;
}

int plus(int i, int j)
{
	int result;
	result = i + j;

	return result;
}

int minus(int i, int j)
{
	int result;
	result = i - j;

	return result;
}

int multiply(int i, int j)
{
	int result;
	result = i * j;

	return result;
}

float divide(int i, int j)
{
	float result;
	result = (float)i / (float)j;

	return result;
}
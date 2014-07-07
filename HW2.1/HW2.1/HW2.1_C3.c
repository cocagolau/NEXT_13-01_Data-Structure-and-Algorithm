/*
     작성일 : 13.03.12 AM 09:40
     작성자 : 서동규
     과제명 : HW#2.1.C3
	 프로그램 소개: 1이상 정수를 입력시 입력된 정수부터 1까지 합을 구하는 프로그램
*/

#include<stdio.h>

int Sum(int i);

int main(void)
{
	int num, result;

	printf("input your number = ");
	scanf("%d", &num);

	result = Sum(num);
	printf("1부터 %d까지의 합 = %d \n", num, result);

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
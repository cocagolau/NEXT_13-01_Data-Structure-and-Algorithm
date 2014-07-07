/*
     작성일 : 13.03.12 AM 09:30
     작성자 : 서동규
     과제명 : HW#2.1.C2
	 프로그램 소개: 두 정수를 입력받아 연산하되, 0 0입력시 종료 후 연산수 출력
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

		printf("숫자 두 개를 입력하세요(0 0 -> exit) : ");
		scanf("%d %d", &num1, &num2);

		if(num1==0 && num2==0)
		{
			printf("총 연산 수 : %d\n", count_num-1);
			break;
		}

		result = Add(num1, num2);
		printf("덧셈 결과 : %d\n", result);
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
/*
	작성일: 13년 4월 21일 오후 12시 28분
	작성자: 서동규
	내  용: Recursive Fibonacci 구현 및 연습  */

#include <stdio.h>

int Fibonacci (int num);

int main (void) {
	int num, result;

	printf ("Input Number : ");
	scanf ("%d", &num);

	result = Fibonacci (num);
	printf ("result : %d \n", result);

	return 0;
}

int Fibonacci (int num) {

	int result;

	if (num <= 0) return 0;
	else if (num == 1) return 1;
	else result = Fibonacci (num-1) + Fibonacci (num-2);
	
	return result;
}
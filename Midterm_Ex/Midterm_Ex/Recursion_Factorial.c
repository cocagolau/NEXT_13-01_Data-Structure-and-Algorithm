/*
	작성일: 13년 4월 21일 오후 12시 26분
	작성자: 서동규
	내  용: Recursive Factorial 연습 및 구현 */

#include <stdio.h>

int Factorial (int num);

int main (void) {
	int num, result;

	printf ("Input Num : ");
	scanf ("%d", &num);

	result = Factorial (num);
	printf ("Result %d! : %d \n", num, result);

	return 0;
}

int Factorial (int num) {
	int result;

	if (num<=1) return 1;

	result = num * Factorial (num-1);

	return result;
}

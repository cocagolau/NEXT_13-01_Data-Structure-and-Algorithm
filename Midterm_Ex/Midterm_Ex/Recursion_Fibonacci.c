/*
	�ۼ���: 13�� 4�� 21�� ���� 12�� 28��
	�ۼ���: ������
	��  ��: Recursive Fibonacci ���� �� ����  */

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
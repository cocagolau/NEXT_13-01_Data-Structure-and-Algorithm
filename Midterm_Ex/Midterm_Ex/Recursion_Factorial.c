/*
	�ۼ���: 13�� 4�� 21�� ���� 12�� 26��
	�ۼ���: ������
	��  ��: Recursive Factorial ���� �� ���� */

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

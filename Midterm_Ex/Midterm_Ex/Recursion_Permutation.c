/*
	�ۼ���: 13�� 4�� 21�� ���� 8�� 44��, 9�� 30��
	�ۼ���: ������
	��  ��: Recursive Permutation ���� �� ���� */

#include <stdio.h>

void Perm (int *list, int start, int end);
void Swap (int *A, int *B);

int main (void) {
	
	int list[4] = {'a','b','c'};
	Perm (list, 0, 2);
	return 0;
}

void Perm (int *list, int start, int end) {

	int i;

	// ��������
	if (start==end) {
		for (i=0; i<=end; i++) {
			printf ("%c", list[i]);
		}
		printf ("\n");
		return;
	}

	for (i=start; i<=end; i++) {
		Swap (list+start, list+i);
		Perm (list, start+1, end);
		Swap (list+start, list+i);
	}

	return;
}
void Swap (int *A, int *B) {
	int temp;

	temp = *A;
	*A = *B;
	*B = temp;

	return;
}
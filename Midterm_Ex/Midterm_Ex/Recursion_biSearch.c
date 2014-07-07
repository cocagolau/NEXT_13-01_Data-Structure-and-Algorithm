/*
	�ۼ���: 13�� 4�� 21�� ���� 1�� 31��
	�ۼ���: ������
	��  ��: Recursive Binary Search ���� �� ����  */

#include <stdio.h>

int Recur_biSearch (int* list, int key, int left, int right);

int main (void) {
	int list[10] = {1,5,8,10,15,19,20,50,100,200};
	int result, key;

	printf ("Input Key : ");
	scanf ("%d", &key);

	result = Recur_biSearch (list, key, 0, 9);
	printf ("result- key: %d, result: %d \n", result, list[result]);

	return 0;
}

int Recur_biSearch (int* list, int key, int left, int right) {
	int mid;
	if (left > right) return -1;

	mid = left + (right-left)/2;
	if (list[mid] == key) return mid;
	else if (list[mid] > key) Recur_biSearch (list, key, left, mid-1);
	else Recur_biSearch (list, key, mid+1, right);
}


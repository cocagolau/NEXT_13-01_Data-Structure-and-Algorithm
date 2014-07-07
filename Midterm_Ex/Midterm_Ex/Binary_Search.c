/*
	�ۼ���: 13�� 4�� 21�� ����11�� 40��
	�ۼ���: ������
	��  ��: Binary Search ���� �� ���� */

#include <stdio.h>

int binarySearch (int *list, int key, int left, int right);

int main (void) {

	int list[10] = {1,3,5,10,14,19,25,46,100,200};
	int result, inputNum;

	printf ("Input Number : ");
	scanf ("%d", &inputNum);

	result = binarySearch (list, inputNum, 0, 9);

	if (result == -1)
		printf ("None \n");
	else if (result == -2)
		printf ("result : None \n");
	else
		printf ("result-key: %d, data: %d \n", result, list[result]);

	return 0;
}


int binarySearch (int *list, int key, int left, int right) {

	int mid;

	if (list==NULL) return -1;

	while (left<=right) {
		mid = left + (right-left)/2;

		if (list[mid] == key)
			return mid;
		else if (list[mid] > key)
			right = mid-1;
		else
			left = mid+1;
	}

	return -2;

}
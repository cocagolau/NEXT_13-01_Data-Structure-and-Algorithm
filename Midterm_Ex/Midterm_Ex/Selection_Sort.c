/*
	작성일 : 13년 4월 21일 오전 10시 47분
	작성자 : 서동규
	내  용 : Selection Sort 연습 */

#include <stdio.h>

void selectionSort (int *list, int num);
void valueSwap (int *valueA, int *valueB);

int main (void) {

	int list[9] = {4,3,6,8,1,9,2,5,7};
	int listNum = 9, i;

	selectionSort (list, 9);

	for (i=0; i<listNum; i++) {
		printf ("%2d", list[i]);
	}
	printf ("\n");

	return 0;
}

void selectionSort (int *list, int num) {

	int minId, Id, i;

	for (Id=0; Id<num-1; Id++) {
		minId = Id;
		for (i=Id+1; i<num; i++) {
			if (list[i] < list[minId])
				minId = i;
		}
		valueSwap (list+Id, list+minId);
	}

	return;
}

void valueSwap (int *valueA, int *valueB) {

	int temp;

	temp = *valueA;
	*valueA = *valueB;
	*valueB = temp;

	return;
}
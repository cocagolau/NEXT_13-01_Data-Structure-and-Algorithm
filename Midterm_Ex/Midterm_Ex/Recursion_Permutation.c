/*
	작성일: 13년 4월 21일 오후 8시 44분, 9시 30분
	작성자: 서동규
	내  용: Recursive Permutation 구현 및 연습 */

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

	// 종료조건
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
/*
	작성일: 13년4월7일 오후2시 25분
	작성자: 서동규
	프로그램 내용: 5by5 행렬을 희소행렬로 변화
*/

#include <stdio.h>
#include <stdlib.h>

void printMatrix(int list[5][5]);
void printSparseMatrix(int list[5][5]);
void recoverMatrix(int sparse_list[][3]);

int main(void)
{
	int list[5][5]={0,0,1,0,0,0,0,0,2,0,0,3,0,0,0,4,0,0,0,5,1,2,0,0,0};

	printMatrix(list);
	printf("-----------------\n");
	printSparseMatrix(list);

	return 0;
}

void printMatrix(int list[5][5])
{
	int i,j;

	for (i=0; i<5; i++) {
		for (j=0; j<5; j++) {
			printf("%2d", list[i][j]);
		}
		printf("\n");
	}

	return;
}

void printSparseMatrix(int list[5][5])
{
	int sparse_list[100][3];
	int i,j, count = 0;

	sparse_list[0][0] = 5;
	sparse_list[0][1] = 5;

	for (i=0; i<5; i++) {
		for (j=0; j<5; j++) {
			if (list[i][j] != 0) {
				count++;
				sparse_list[count][0] = i;
				sparse_list[count][1] = j;
				sparse_list[count][2] = list[i][j];
			}
		}
	}

	sparse_list[0][2] = count;

	for (i=0; i<=count; i++) {
		for (j=0; j<3; j++) {
			printf("%2d", sparse_list[i][j]);
		}
		printf("\n");
	}

	printf("----------------------\n");
	recoverMatrix(sparse_list);

	return ;
}

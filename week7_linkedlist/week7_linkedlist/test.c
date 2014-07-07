/*
	�ۼ���: 13��4��7�� ����1��20��
	�ۼ���: ������
	���α׷� ����: NbyN ��Ŀ� �ﰢ��'*'���
	              ref: �ڱ��� 5��-3.pdf p30
*/

#include <stdio.h>
#include <stdlib.h>

void printArrayStar(int** list, int star_num);
int** inputArrayStar(int** list, int star_num);

int main(void)
{
	int i, star_num;
	int **list;

	printf("Input the size of list : ");
	scanf("%d", &star_num);

	list = (int**) malloc (sizeof(int*) * star_num);

	for (i=0; i<star_num; i++) {
		list[i] = (int*) calloc (sizeof(int), star_num);
	}

	list = inputArrayStar (list, star_num);
	printArrayStar (list, star_num);

	for (i=0; i<star_num; i++) {
		free(list[i]);
		list[i] = (int*)NULL;
	}
	free(list);
	list = (int**)NULL;

	return 0;
}

int** inputArrayStar(int** list, int star_num)
{

	int i,j;

	for (i=0; i<star_num; i++) {
		for (j=0; j<=i; j++) {
			list[i][j] = '*';
		}
	}

	return list;
}

void printArrayStar(int** list, int star_num)
{

	int i,j;

	for (i=0; i<star_num; i++) {
		for (j=0; j<=i; j++) {
			printf("%c",list[i][j]);
		}
		printf("\n");
	}
}
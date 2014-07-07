/*
     작성일 : 13.03.25 AM 1:50
     작성자 : 서동규
     과제명 : HW#3.1.C4
*/

#include<stdio.h>
#include<stdlib.h>

void blean(int* list, int list_size, int digit);
void bprint(int* list, int list_size);

int main(void)
{
	int* list=NULL;
	int list_size;

	printf("Input : ");
	scanf("%d", &list_size);

	list = (int*)malloc(sizeof(int)*list_size);

	blean(list, list_size, 0);

	free(list);
	list = NULL;

	return 0;
}

void blean(int* list, int list_size, int digit)
{
	int i;

	if(list_size == digit){
		bprint(list, list_size);
	}
	else{
		for(i=0; i<=1; i++){
			list[digit] = i;
			blean(list, list_size, digit+1);
		}
	}
}

void bprint(int* list, int list_size)
{
	int i;
	for(i=0; i<list_size; i++){
		printf("%d", list[i]);
	}
	printf("\n");
}
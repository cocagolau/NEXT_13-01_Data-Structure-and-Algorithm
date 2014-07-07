/*
     작성일 : 13.03.25 AM 3:23
     작성자 : 서동규
     과제명 : HW#3.1.C7
*/

#include<stdio.h>
#include<stdlib.h>

void blean(int* list, int list_chk[], int list_size, int digit);
void bprint(int* list, int list_chk[], int list_size);


int main(void)
{
	int* list = NULL;
	int* list_chk = NULL;
	int list_size, i;

	printf("Input : ");
	scanf("%d", &list_size);

	list = (int*)malloc(sizeof(int)*list_size);
	list_chk = (int*)malloc(sizeof(int)*list_size);
	
	for(i=0; i<list_size; i++){
		list[i] = 'a'+i;
	}

	printf("{\n");
	blean(list, list_chk, list_size, 0);
	printf("}\n");
	
	free(list);
	list = NULL;

	free(list_chk);
	list_chk = NULL;

	return 0;
}

void blean(int* list, int list_chk[], int list_size, int digit)
{
	int i;

	if(list_size == digit){
		bprint(list, list_chk, list_size);
	}
	else{
		for(i=0; i<=1; i++){
			list_chk[digit] = i;
			blean(list, list_chk, list_size, digit+1);
		}
	}
}

void bprint(int* list, int list_chk[], int list_size)
{
	int i, sum=0;

	printf(" {");
	for(i=0; i<list_size; i++){
		sum = sum + list_chk[i];
	}

	for(i=0; i<list_size; i++){
		if(list_chk[i] != 0){
			if(sum>1){
				printf("%c, ", list[i]);
				sum--;
			}
			else{
				printf("%c", list[i]);
			}
		}
	}
	printf("},\n");
}
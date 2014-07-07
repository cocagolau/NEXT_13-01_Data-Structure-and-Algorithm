/*
	작성일: 24일 오후 8시 15분
	작성자: 서동규
	과제명: HW3.1_test2.c
*/

#include<stdio.h>

void perm(int list[], int list_chk[], int list_size, int digit);
void list_print(int list[], int list_size);

int main(void)
{
	int list[]={'a','b','c'};
	int list_chk[]={'F','F','F'};
	int list_size = sizeof(list)/sizeof(int);
	printf("%d\n", list_size);
	perm(list,list_chk,list_size-1, 0);

	return 0;
}

void perm(int list[], int list_chk[], int list_size, int digit)
{
	int chk_num;

	if(list_size+1 == digit){
		list_print(list, list_size);
	}
	for(chk_num = 0; chk_num<=list_size; chk_num++){
		if(list_chk[chk_num] == 'F'){
			list_chk[chk_num] = 'T';
			list[digit] = 'a' + chk_num;

			perm(list, list_chk, list_size, digit+1);
			
			list_chk[chk_num] = 'F';
			list[digit] = 0;

		}
	}
}

void list_print(int list[], int list_size)
{
	int i;

	for(i=0; i<=list_size; i++){
		printf("%c", list[i]);
	}
	printf("\n");
}
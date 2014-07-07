/*
     작성일 : 13.03.25 AM 2:36
     작성자 : 서동규
     과제명 : HW#3.1.C2
*/

#include<stdio.h>

void blean(int list[], int list_chk[], int list_size, int digit);
void bprint(int list[], int list_chk[], int list_size);

int main(void)
{
	int list[3] = {'a','b','c'};
	int list_chk[3];

	blean(list, list_chk, 3, 0);

	return 0;
}

void blean(int list[], int list_chk[], int list_size, int digit)
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

void bprint(int list[], int list_chk[], int list_size)
{
	int i,sum=0;
	for(i=0; i<list_size; i++){
		if(list_chk[i] != 0){
			printf("%c", list[i]);
			sum = sum + list_chk[i];
		}
	}

	if(sum > 0){
		printf("\n");
	}
}
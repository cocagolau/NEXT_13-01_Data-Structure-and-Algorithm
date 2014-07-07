/*
     작성일 : 13.03.25 AM 4:25
     작성자 : 서동규
     과제명 : HW#3.1.C5
*/

#include<stdio.h>

void sort(int list[], int end);
void swap(int* i, int* j);

int main(void)
{
	int list[3]={0,};
	int i, result;
	
	for(i=0; i<3; i++){
		printf("%d번 입력 : ",i);
		scanf("%d", &list[i]);
	}
	sort(list, 0);

	return 0;
}

void sort(int list[], int end)
{
	int i;
	if(end == 2){
		for(i=0; i<=2; i++){
			printf("%d", list[i]);
		}
		printf("\n");
	}
	else{
		for(i=0; i<2-end; i++){
			if(list[i] > list[i+1]){
				swap(&list[i], &list[i+1]);
				sort(list, end+1);
			}
		}
	}
}

void swap(int* i, int* j)
{
	int temp = *i;
	*i = *j;
	*j = temp;
}
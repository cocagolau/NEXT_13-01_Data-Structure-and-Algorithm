/*
     작성일 : 13.03.14 AM 10:10
     작성자 : 서동규
     과제명 : HW#2.2.C1
     프로그램 소개: 배열의 요소를 한칸씩 오른쪽으로 이동 후 마지막 값을 맨앞으로 이동하는 프로그램
*/

#include<stdio.h>

//int arr_shift(int* arr1, int* arr2);

int main(void)
{
	int array1[8]={1,2,3,4,5,6,7,8};
	int array2[8]={array1[7]};
	int i;

	printf("실행 전 : ");
	for(i=0; i<8; i++)
	{
		printf("%d ", array1[i]);

		if(i<7)
			array2[i+1]=array1[i];

	}
	printf("\n");

	printf("실행 후 : ");
	for(i=0; i<8; i++)
	{
		printf("%d ", array2[i]);
	}
	printf("\n");
		
	return 0;
}
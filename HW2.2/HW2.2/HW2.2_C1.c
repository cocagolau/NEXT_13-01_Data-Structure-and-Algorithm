/*
     �ۼ��� : 13.03.14 AM 10:10
     �ۼ��� : ������
     ������ : HW#2.2.C1
     ���α׷� �Ұ�: �迭�� ��Ҹ� ��ĭ�� ���������� �̵� �� ������ ���� �Ǿ����� �̵��ϴ� ���α׷�
*/

#include<stdio.h>

//int arr_shift(int* arr1, int* arr2);

int main(void)
{
	int array1[8]={1,2,3,4,5,6,7,8};
	int array2[8]={array1[7]};
	int i;

	printf("���� �� : ");
	for(i=0; i<8; i++)
	{
		printf("%d ", array1[i]);

		if(i<7)
			array2[i+1]=array1[i];

	}
	printf("\n");

	printf("���� �� : ");
	for(i=0; i<8; i++)
	{
		printf("%d ", array2[i]);
	}
	printf("\n");
		
	return 0;
}
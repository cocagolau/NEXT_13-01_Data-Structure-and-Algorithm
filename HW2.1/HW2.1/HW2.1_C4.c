/*
     �ۼ��� : 13.03.12 PM 1:36
     �ۼ��� : ������
     ������ : HW#2.1.C4
	 ���α׷� �Ұ�: array1�� array2 �迭�� ��Ұ� ���� ���ϴ� ���α׷�
*/

#include<stdio.h>

int main(void)
{
	float array1[5] = {2.2, 3.5, 2.5, 10.1, 4.0};
	float array2[5] = {3.3, 2.0, 4.0, 1.0, 2.5};
	float result;
	int i,j;

	for(i=0; i<5; i++)
	{
		for(j=0; j<5; j++)
		{
			result = array1[i]*array2[j];
			printf("%5.2f * %5.2f = %5.2f \n", array1[i],array2[j],result);
		}
	}

	return 0;
}
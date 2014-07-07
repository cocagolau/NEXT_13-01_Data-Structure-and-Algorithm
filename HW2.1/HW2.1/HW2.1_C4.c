/*
     작성일 : 13.03.12 PM 1:36
     작성자 : 서동규
     과제명 : HW#2.1.C4
	 프로그램 소개: array1과 array2 배열의 요소간 곱을 구하는 프로그램
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
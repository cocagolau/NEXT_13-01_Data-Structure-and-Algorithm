/*
     작성일 : 13.03.12 PM 18:50
     작성자 : 서동규
     과제명 : HW#2.1.C5
	 프로그램 소개: *과 &를 이용한 각 배열 요소의 값과 주소를 출력하는 프로그램
*/

#include<stdio.h>

int main(void)
{
	char array1[5] = {'A','B','C','D','E'};
	int array2[5] = {10,20,30,40,50};
	double array3[5] = {10.1, 20.2, 30.3, 40.4, 50.5};

	printf("%8x %8x %8x %8x %8x \n", array1, array1+1, array1+2, array1+3, array1+4);
	printf("%8x %8x %8x %8x %8x \n", &array1[0], &array1[1], &array1[2], &array1[3], &array1[4]);
	printf("%8c %8c %8c %8c %8c \n", *(array1), *(array1+1), *(array1+2), *(array1+3), *(array1+4));
	printf("%8c %8c %8c %8c %8c \n", array1[0], array1[1], array1[2], array1[3], array1[4]);
	printf("%8c %8c %8c %8c %8c \n\n", *&array1[0], *&array1[1], *&array1[2], *&array1[3], *&array1[4]);
	
	printf("%8x %8x %8x %8x %8x \n", array2, array2+1, array2+2, array2+3, array2+4);
	printf("%8x %8x %8x %8x %8x \n", &array2[0], &array2[1], &array2[2], &array2[3], &array2[4]);
	printf("%8d %8d %8d %8d %8d \n", *(array2), *(array2+1), *(array2+2), *(array2+3), *(array2+4));
	printf("%8d %8d %8d %8d %8d  \n", array2[0], array2[1], array2[2], array2[3], array2[4]);
	printf("%8d %8d %8d %8d %8d  \n\n", *&array2[0], *&array2[1], *&array2[2], *&array2[3], *&array2[4]);

	printf("%8x %8x %8x %8x %8x \n", array3, array3+1, array3+2, array3+3, array3+4);
	printf("%8x %8x %8x %8x %8x \n", &array3[0], &array3[1], &array3[2], &array3[3], &array3[4]);
	printf("%8.3lf %8.3lf %8.3lf %8.3lf %8.3lf \n", *(array3), *(array3+1), *(array3+2), *(array3+3), *(array3+4));
	printf("%8.3lf %8.3lf %8.3lf %8.3lf %8.3lf \n", array3[0], array3[1], array3[2], array3[3], array3[4]);
	printf("%8.3lf %8.3lf %8.3lf %8.3lf %8.3lf \n\n", *&array3[0], *&array3[1], *&array3[2], *&array3[3], *&array3[4]);

	return 0;
}

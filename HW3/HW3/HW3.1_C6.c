/*
     작성일 : 13.03.25 AM 8:11
     작성자 : 서동규
     과제명 : HW#3.1.C6
*/

#include<stdio.h>

void tower(int num, int x, int z, int y);

int main(void)
{
	int num;
	printf("타워의 갯수 입력 : ");
	scanf("%d", &num);

	tower(num, 1,2,3);

	return 0;
}

void tower(int num, int x, int y, int z)
{
	if(num==0){
		return;
	}
	tower(num-1, x, z, y);
	printf("%d --> %d \n", x, z);
	tower(num-1, y, x, z);
}
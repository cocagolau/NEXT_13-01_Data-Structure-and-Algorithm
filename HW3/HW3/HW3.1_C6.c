/*
     �ۼ��� : 13.03.25 AM 8:11
     �ۼ��� : ������
     ������ : HW#3.1.C6
*/

#include<stdio.h>

void tower(int num, int x, int z, int y);

int main(void)
{
	int num;
	printf("Ÿ���� ���� �Է� : ");
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
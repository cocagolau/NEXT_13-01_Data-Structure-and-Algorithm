#include<stdio.h>
int main(void)
{
	int hour, minute, second;
	int result;

	printf("���� �� ���ΰ���?(0~23) : ");
	scanf("%d", &hour);

	printf("���� �� ���ΰ���?(0~59) : ");
	scanf("%d", &minute);

	printf("���� �� ���ΰ���?(0~59) : ");
	scanf("%d", &second);

	result = (hour*60*60) + (minute*60) + second;
	printf("\n00�� 00�� 00�ʸ� �������� %d�ʰ� �귶���ϴ�.\n", result);

	return 0;
}
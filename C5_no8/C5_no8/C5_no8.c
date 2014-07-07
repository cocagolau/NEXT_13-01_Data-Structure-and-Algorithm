#include<stdio.h>
int main(void)
{
	int hour, minute, second;
	int result;

	printf("현재 몇 시인가요?(0~23) : ");
	scanf("%d", &hour);

	printf("현재 몇 분인가요?(0~59) : ");
	scanf("%d", &minute);

	printf("현재 몇 초인가요?(0~59) : ");
	scanf("%d", &second);

	result = (hour*60*60) + (minute*60) + second;
	printf("\n00시 00분 00초를 기준으로 %d초가 흘렀습니다.\n", result);

	return 0;
}
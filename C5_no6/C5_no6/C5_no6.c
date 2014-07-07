#include<stdio.h>
int main(void)
{
	int whole_life = 100, year = 365, day_min = 24*60;
	int ciga, smoking_year=20, smoking_time;
	int smok_day, smok_hour, smok_min, result;

	printf("하루에 몇 개피씩 피우시나요? : ");
	scanf("%d", &ciga);

	smoking_time = smoking_year * year * ciga * 2;
	smok_day = smoking_time / day_min;
	smok_hour = (smoking_time % day_min) / 60;
	smok_min = smoking_time % day_min % 60;

	result = ((whole_life * year * day_min) - smoking_time) / (year * day_min);
	
	printf("수명 단축 시간: %d일 %d시간 %d분 \n  %d살까지 살 수 있음\n", smok_day, smok_hour, smok_min, result);
	return 0;
}
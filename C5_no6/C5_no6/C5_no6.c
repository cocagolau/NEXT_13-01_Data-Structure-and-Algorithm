#include<stdio.h>
int main(void)
{
	int whole_life = 100, year = 365, day_min = 24*60;
	int ciga, smoking_year=20, smoking_time;
	int smok_day, smok_hour, smok_min, result;

	printf("�Ϸ翡 �� ���Ǿ� �ǿ�ó���? : ");
	scanf("%d", &ciga);

	smoking_time = smoking_year * year * ciga * 2;
	smok_day = smoking_time / day_min;
	smok_hour = (smoking_time % day_min) / 60;
	smok_min = smoking_time % day_min % 60;

	result = ((whole_life * year * day_min) - smoking_time) / (year * day_min);
	
	printf("���� ���� �ð�: %d�� %d�ð� %d�� \n  %d����� �� �� ����\n", smok_day, smok_hour, smok_min, result);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
void process() {
	int year, month, day;
	scanf("%d%d%d", &year, &month, &day);
	int fab = 28;
	int sum = day;
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) fab=29; // 如果是闰年标记
	switch (month)
	{
	case 12:sum += 30;
	case 11:sum += 31;
	case 10: sum += 30;
	case 9:sum += 31;
	case 8:sum += 31;
	case 7:sum += 30;
	case 6:sum += 31;
	case 5:sum += 30;
	case 4:sum += 31;
	case 3:sum += fab;
	case 2:sum += 31;
	case 1: break;
	}
	printf("%d\n",sum);
}

int main()
{
	int n;
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		process();
	}
	return 0;
}
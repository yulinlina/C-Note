#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

void process() {
	int a, b, c;
	int flag = 0;
	int i;
	scanf("%d%d%d", &a, &b, &c);
	for (i = 1; i < 34; i++)
	{
		int temp = i * 3 + a;
		if (temp % 5 == b && temp % 7 == c)
		{
			printf("%d\n", temp);
			flag = 1;
		}
	}
	if (flag == 0)
		printf("Impossible\n");
}
int main()
{
	int num;
	int i;
	scanf("%d", &num);
	for (i = 0; i < num; i++)
	{
		process();
	}
	return 0;
}
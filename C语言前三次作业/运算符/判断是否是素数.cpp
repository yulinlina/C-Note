#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
void process()
{
	int a;
	scanf("%d", &a);
	int flag = 0;
	if (a <= 1)
	{
		printf("no\n");    // when you only want a 
		flag = 1;
	}
	for (int j = 2; j < a/2; j++)
	{
		
		if ((a % j) == 0)
		{
			printf("no\n");
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		printf("yes\n");

	}
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
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	int a;
	int b;
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d%d", &a, &b);
		if (a > b)
		{
			int tmp = a;
			a = b;
			b = tmp;
		}
		int sum = 0;
		if (a % 2 == 0) 
		{
			a = a + 1;
		}
		int j = 0;
		for(j=a;j<=b;j+=2)
		{
			sum =sum+j;
		}
		printf("%d\n", sum);
	}
	return 0;
}

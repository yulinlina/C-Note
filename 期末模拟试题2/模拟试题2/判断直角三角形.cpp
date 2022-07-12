#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	scanf("%d", &n);
	int i = 0;
	int a, b, c;
	int tmp;
	for (i = 0; i < n; i++) {
		scanf("%d%d%d", &a,&b,&c);
		fflush(stdin);
		tmp = a;
		if (a > b)
		{
			a = b;
			b = tmp;
		}
		if (a > c)
		{
			a = c;
			c = tmp;
		}
		tmp = b;
		if (b > c)
		{
			b = c;
			c = tmp;
		}
		if (a * a + b * b == c * c)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
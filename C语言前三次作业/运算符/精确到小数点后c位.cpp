#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
void process() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	if (a > b)
	{
		int tmp = a / b;
		int remain = a % b;
		printf("%d.", tmp);
		int i, n = 0;
		for (i = 0; i < c; i++)
		{
			n = remain * 10 / b;
			printf("%d", n);
			remain = remain * 10 % b;
		}
		printf("\n");
	}
	else 
	{
		
		int i, n = 0;
		printf("0.");
		for (i = 0; i < c; i++)
		{
			n = a * 10 / b; // х║ил
			printf("%d", n);
			a = a * 10 % b; // get the remain
		}
		printf("\n");
	}
}
int main()
{
	int n;
	int i;
	double m;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		process();
	}
	return 0;
}
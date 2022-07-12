#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

void process() 
{
	int n;
	scanf("%d", &n);
	int i, j, k;
	int tmp;
	if (n % 2 != 1) printf("error\n");
	else 
	{
		printf("print");
		for(i=1;i<=n;i++)
		{
			for (tmp = 1; tmp <= n - i;tmp++)printf(" ");
			for ( j= 1; j<=i; j++) printf("%d", j);
			for ( k = j-1; k > 1; k--)printf("%d", k - 1);
			printf("\n");
		}
		for (i = n-1; i >=1; i--)
		{
			printf("%*s", n - i, " ");
			for (j = 1; j <= i; j++) printf("%d", j);
			for (k = j-1; k > 1; k--)printf("%d", k - 1);
			printf("\n");
		}
	}
}
int main()
{
	int num;
	int l;
	scanf("%d", &num);
	for (l = 0; l < num; l++)
	{
		process();
	}
	return 0;
}
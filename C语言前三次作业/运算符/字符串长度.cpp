#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	int i;
	char a;
	scanf("%d", &n);
	a = getchar();
	for (i = 0; i < n; i++)
	{
		int count = 0;
		int counta = 0;
		a = getchar();
		while (a != '\n')   // 可以把a = getchar()写在前面
		{
			/*if (a == ' ') {
				a = getchar();
				continue;
			}*/
			if (a == 'a')
				counta++;
			count++;
			a = getchar();
		}
		printf("%d %d\n", count, counta);
	}
	return 0;
}
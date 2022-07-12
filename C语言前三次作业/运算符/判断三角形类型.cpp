#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
int main()
{
	int n, i, a, b, c;
	scanf("%d", &n);
	for (i = 0; i < n; i++) 
	{
		scanf("%d,%d,%d", &a, &b, &c);
		fflush(stdin);
		int tmp = a;
		if (a > b)
		{
			a = b;
			b = tmp;
		}
		if (a >c)
		{
			a = c;
			c = tmp;
		}
		tmp = b;
		if (b >c)
		{
			b = c;
			c = tmp;
		}
		int illegal = 0;
		if (a + b <= c) {
			printf("illegal\n");
			illegal = 1;
		}
		if (!illegal)
		{
		if (a * a + b * b == c * c)
			printf("right\n");
		else if (a * a + b * b < c * c)
			printf("obtuse\n");
		else if(a * a + b * b > c * c)
			printf("acute\n");
		}
	}
		return 0;
}
//double cos(int x,int y,int z)
//{
//	double cos;
//	double a = x;
//	double b = y;
//	double c = z;
//	cos = (b * b + c * c - a * a) /( 2 * b * c);
//	return cos;
//}
	//	int illegal = 0;
	//	if (cos(a, b, c) == -1 || cos(b, a, c) ==-1 || cos(c, b, a) == -1)
	//	{
	//		printf("illegal\n");
	//		illegal = 1;
	//		continue;
	//	}
	//	if (illegal == 0) {
	//		if (fabs(cos(a, b, c)) <1e-15 || fabs(cos(b, a, c))<1e-15 || fabs(cos(c, b, a))<1e-15)
	//		{
	//			printf("right\n");
	//			//continue;
	//		}
	//		if (cos(a, b, c) > 0 && cos(b, a, c) > 0 && cos(c, b, a) > 0)
	//		{
	//			printf("acute\n");
	//			//continue;
	//		}
	//		if (cos(a, b, c) < 0 || cos(b, a, c) < 0 || cos(c, b, a) < 0)
	//		{
	//			printf("obtuse\n");
	//			//continue;
	//		}
	//	}
	//}


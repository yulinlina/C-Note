#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
void process() {
	float m;
	scanf("%f", &m);    
	double j = 0;
	double sum = 0;
	int i = 1;
	for (j = 1; j <= m; j++)
	{
		i++;
		sum += j / (3+(2+j)*(j-1)/2) * pow(-1, j + 1);
	}
	printf("%.4f\n", sum);

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
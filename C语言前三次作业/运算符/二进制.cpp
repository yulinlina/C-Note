#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
void process() {
	int m;
	int a[30] = { 0 };
	int i = 0;
	scanf("%d", &m);
	while (m) {
		if (m % 2 == 1) {
			a[i] = 1;
				i++;
		}
		m = m / 2;
	}
	int j = 0;
	int count = 0;
	for (j = 0; j < 30; j++) {
		if (a[j] == 1)
			count++;
	}
	printf("%d\n", count);
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
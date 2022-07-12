#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
void process() {
	int m, n;
	scanf("%d%d", &m, &n);
	if (m < n) {
		int tmp = m;
		m = n;
		n = tmp;
	}
	while (n) {
		int tmp = n;
		n = m % n;
		m = tmp;
	}
	printf("%d\n", m);
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
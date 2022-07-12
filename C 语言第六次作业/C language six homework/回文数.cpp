#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
void process() {
	int i = 0;
	int flag = 0;
	int a[100] = { 0 };
	int n;
	scanf("%d", &n);
	while (n) {
		a[i] = n % 10;
		n /= 10;
		i++;
	}
	int k;
	for (k = 0; k < (i/2); k++) {
		if (a[k] != a[i - 1 - k]) {
			printf("no\n");
			flag = 1;
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
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
void process()
{
	int n, i,j;
	scanf("%d", &n);
	int a[100] = { 0};
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 0; i < n; i++) {
		if (a[i] == 0) {
			for (j = i; j < n; j++) {
				a[j] = a[j + 1];
			}
		}
	}
	for (i = 0; i < n; i++) {
		printf("%d ", a[i]);
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
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
void process() {
	int a[6] = {0};
	int i = 0;
	float sum = 0;
	for (i = 0; i < 6; i++) {
		scanf("%d", &a[i]);
	}
	for (i = 0; i < 6; i++) {
		sum += a[i];
	}
	float e = sum / 6;
	printf("%.2f ", e);
	float d = 0;
	for (i = 0; i < 6; i++) {
		d += (a[i] - e)* (a[i] - e);
	}
	printf("%.2f\n", d/6);
	
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
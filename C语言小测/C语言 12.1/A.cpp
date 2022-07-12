#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
void process() {
	int m;
	int i = 0;
	int a[100] = { 0 };
	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		scanf("%d", &a[i]);
	}
	int min = a[0];
	for (i = 1; i < m; i++) {
		if (a[i] <= min) min = a[i];
	}
	int sec_min =a[0];
	for (i = 0; i < m; i++) {
		if (a[i] != min) sec_min = a[i];
	}
	for (i = 0; i < m; i++) {
		if ((a[i] != min) && (a[i] <= sec_min))sec_min = a[i];
	}
	if (sec_min == min) printf("ERROR\n");
	else printf("%d\n", sec_min);
}
int main() {
	int n = 0;
	scanf("%d", &n);
	int i = 0;
	for (i = 0; i < n; i++) {
		process();
	}
	return 0;
}
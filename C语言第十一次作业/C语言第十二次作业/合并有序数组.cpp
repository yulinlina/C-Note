#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
int main() {
	int m, n;
	scanf("%d%d", &m, &n);
	int i = 0;
	int a[100] = { 0 };
	int b[100] = { 0 };
	int c[100] = { 0 };
	for (i = 0; i < m; i++) {
		scanf("%d", a + i);
	}
	for (i = 0; i < n; i++) {
		scanf("%d", b + i);
	}
	int min = m < n ? m : n;
	int max = m > n ? m : n;
	i = 0;
	int* pa = a;
	int* pb = b;
	int j = 0;
	int k = 0;
	while ((j<m)&&(k<n))
	{
		if (*pa<=*pb) {
			c[i] = *pa;
			pa++;
			j++;
		}
		else {
			c[i] = *pb;
			pb++;
			k++;
		}
		i++;
	}
	if (k==n) {
		while (i < m+n) {
			c[i] = *pa;
			i++;
			pa++;
		}
	}
	else {
		while (i < m+n) {
			c[i] = *pb;
			i++;
			pb++;
		}
	}
	for (i = 0; i < m+n; i++) {
		printf("%d ", c[i]);
	}
}
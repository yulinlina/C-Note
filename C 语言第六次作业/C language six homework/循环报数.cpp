#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
void process()
{
	int n;
	int i;
	int j = 1;
	scanf("%d", &n);
	int a[100] = { 0 };
	int b[100] = { 0 };
	for (i = 0; i < n; i++) {   // ±àºÅ
		a[i] = i;
	}
	int count = 0;
	while (count != n - 1) {
		for (i = 0; i < n; i++) {
			if (b[a[i]] == 3) continue;
			b[a[i]] = (j % 3);
			if (j % 3 == 0) {
				b[a[i]] = 3;
				count++;
			}
			j++;   // Ñ­»·±¨Êý
		}
	}
	for (i = 0; i < n; i++) {
		if (b[i] != 3) printf("%d\n", i+1);
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
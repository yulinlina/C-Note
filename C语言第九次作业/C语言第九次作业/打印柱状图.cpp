#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
void process(int n) {
	int i = 0,j=0;
	int a[10] = { 0 };
	int max = a[0];
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if ((a[i] > 10) || (a[i]) < 0) {
			printf("Input Error");
			return;
		}
		if (a[i] > max) max = a[i];
	}  // Ѱ�ҵ�����ֵ��ȷ��Y�������᳤��
	for (i = 0; i < max; i++) {
		for (j = 0; j < n; j++) {
			if (a[j]>=max - i) printf("*"); // ��ÿһ�� �жϻ����ٸ�-�����ٸ�*
			else printf("-");
		}
		printf("\n");
	}
}
int main() {
	int n;
	scanf("%d", &n);
	process(n);
}
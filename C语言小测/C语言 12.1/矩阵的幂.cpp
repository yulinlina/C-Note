#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>

void process() {
	int n = 0;
	int k = 0;
	scanf("%d%d", &n, &k);
	long  a[10][10] = { 0 }; // 长整型
	long tmp[10][10] = { 0 };
	long result[10][10] = { 0 };
	int i, j,m,col;
	int tmp_num= 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%ld", &a[i][j]);
			result[i][j] = a[i][j];
		}
	}
	for (m = 0; m < k-1; m++) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				for (col = 0; col < n; col++) {
					tmp[i][j] += result[i][col] * a[col][j];  
				}
			}
			// 这里不能马上赋值，因为会更改了原result的值 
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				result[i][j] = tmp[i][j];
				tmp[i][j] = 0;
			}
		}
	}
	
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%ld ", result[i][j]);
		}
		printf("\n");
	}
}
int main() {
	process();
	return 0;
}
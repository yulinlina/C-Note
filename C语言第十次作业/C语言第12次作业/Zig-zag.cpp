#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
void process() {
	int m;
	int n;
	scanf("%d%d", &m, &n);
	int i = 0, j = 0;
	int a[100][100] = { 0 };
	int flag = 1;
	int col = 0, row = 0;
	int count = 1;
	int max = m > n ? m : n;
	int min = m < n ? m : n;
	int sign = 0;
	for (i = 0; i < max; i++) {  // 上三角
		col = i;
		row = 0;
		//if (i == min)break;
		if (flag == 0) { // 顺序 从上往下
			while (col > n - 1) {
				col--;
				row++;
			}
			while ((col >= 0) && (row < m)) {
				a[row][col] = count++;
				row++;
				col--;
			}
			flag = 1;
		}
		else { // flag ==0
			col = 0; row = i;
			while (row > m - 1) {
				row--;
				col++;
			}
			while ((col < n) && (row >= 0) && (row < m)) { // 逆序 从下往上 
				a[row][col] = count++;
				row--;
				col++;
				sign = 1;  // 下一次从上到下
			}
			if (sign) flag = 0;
			sign = 0;
		}
	}
	for (i = 1; i < max; i++) { // 下三角
		col = i; row = max-1;
		if (i == min) break;
		if (flag == 1) {  // 从下往上
			while (row > m-1) {
				col++;
				row--;
			}
			while ((col < n) && (row >= 0)) {
				a[row][col] = count++;
				col++;
				row--;
				flag = 0;
			}
		}
		else {  //从上往下 flag ==0
			row = i;
			col = max-1;
			while (col>n-1)
			{
				col--;
				row++;
			}
			while ((row < m) && (col > 0) && (col < n)) {
				a[row][col] = count++;
				col--;
				row++;
				flag = 1;
			}
		}
	}
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}
int main() {
	process();
}
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
int m, n;
void Swith_row(int a[][50],int m, int n, int x1,int x2) {
	int tmp = 0;
	int i = 0;
	x1 = x1 - 1; // 对应的数组所在下标
	x2 = x2 - 1;
	for (i = 0; i < n; i++) {
		tmp = a[x1][i];
		a[x1][i] = a[x2][i];
		a[x2][i] = tmp;
	}
}
void delete_row(int a[][50], int x) { // 传入行数与列数
	int i = 0;
	int j = 0;
	x= x - 1;
	for (j = x; j < m; j++) {
		for (i = 0; i < n; i++) {
			a[j][i] = a[j+1][i];  // 从后往前依次覆盖
		}
	}
	m = m - 1;
}
void insert_row(int a[][50],  int x) {
	int i = 0;
	int j = 0;
	x = x - 1;
	for (j = m-1; j >= x; j--) {
		for (i = 0; i < n; i++) { // 倒序依次后移
			a[j + 1][i] = a[j][i];
		}
	}
	j = x;
	for (i = 0; i < n; i++) {  // 该行全为0
		a[j][i] = 0;
	}
	m = m +1;
}
void insert_col(int a[][50], int y) {
	int i = 0;
	int j = 0;
	y = y - 1;
	for (j = n - 1; j >= y; j--) {
		for (i = 0; i < n; i++) {
			a[i][j + 1] = a[i][j];
		}
	}
	j = y;
	for (i = 0; i < n; i++) {  // 该列全为0
		a[i][j] = 0;
	}
	n = n + 1;

}
void Swith_col(int a[][50], int m, int n, int y1, int y2) {
	int tmp = 0;
	int i = 0;
	y1 = y1 - 1;
	y2 = y2 - 1;
	for (i = 0; i < m; i++) {
		tmp = a[i][y1];
		a[i][y1] = a[i][y2];
		a[i][y2] = tmp;
	}
}
void delete_col(int a[][50], int y) { // 传入行数与列数 ? 全局变量？
	int i = 0;
	int j = 0;
	y = y - 1;
	for (j = y; j < n; j++) {
		for (i = 0; i < m; i++) {
			a[i][j] = a[i][j + 1]; // 从后往前依次覆盖
		}
	}
	n -= 1;
}
int main() {
	scanf("%d%d", &m, &n);
	int a[50][50] = { 0 };
	int i = 0;
	int j = 0;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	int k = 0;
	scanf("%d", &k);
	char op[3];
	int x, y;
	for (i = 0; i < k; i++) {
		scanf("%s", op);
		scanf("%d", &x);
		if (strcmp(op, "SR") == 0) {
			scanf("%d", &y);
			Swith_row(a, m, n, x, y);
		}
		else if (strcmp(op, "SC") == 0) {
			scanf("%d", &y);
			Swith_col(a, m, n, x, y);
		}
		else if (strcmp(op, "DR") == 0) {
			delete_row(a, x);
		}
		else if (strcmp(op, "DC") == 0)
		{
			delete_col(a,x);
		}
		else if (strcmp(op, "IR") == 0) {
			insert_row(a, x);
		}
		else //(strcmp(op, "CI") == 0) 
		{
			insert_col(a,x);
		}
	}
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
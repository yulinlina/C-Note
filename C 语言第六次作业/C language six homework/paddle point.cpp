#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
void process()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int i, j;
	int flag = 0;
	int col=0;
	int row;
	int count = 0;
	int a[50][50] = {0};
	for (i = 0; i<n; i++) {
		for (j=0;j<m;j++)
		{
			scanf("%d", &a[i][j]);
		}
		
	}
	for (i = 0; i < n; i++) {
		int max = a[i][0];
		for (j = 0; j < m; j++) { // find the max of row
			if (a[i][j] > max) {
				max = a[i][j];
				col = j;
				row = i;
			}
		}
		int min = a[i][col];
		int flag2 = 0;
		for (i = 0; i < n; i++) {
			if (a[i][col] < min) flag2 = 1;
		}
		if (flag2 == 0) {
			printf("a[%d][%d]=%d\n", row, col, min);
			flag = 1;
		}
	}
	if (flag == 0) {
		printf("NO\n");
		}
}
int main()
{
	process();
	/*int n;
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		process();
	}*/
	return 0;
}
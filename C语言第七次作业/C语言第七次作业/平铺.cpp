#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
bool judge(int num) {
	if ((num >= 1) && (num <= 5)) {
		return true;
	}
	return false;
}
void process()
{
	int i = 0;
	int j = 0;
	char a[6][10] = {"--**-**--","-*--*--*-","-*-----*-","--*---*--","---*-*---","----*----" };
	/*for (i = 0; i < 6;i++) {
		for (j = 0; j < 9; j++) {
			printf("%c", a[i][j]);
		}
		printf("\n");
	}*/
	int m, n;
	scanf("%d%d", &m, &n);
	char b[100][100];
	int k = 0;
	int z = 0;
	if (judge(m) && judge(n)) {
		for (z = 0; z < m; z++) {
			for (k = 0; k < 6; k++) {
				for (i = 0; i < n; i++) {
					for (j = 0; j < 9; j++) {
						b[k + 6 * z][j + 9 * i] = a[k][j];
					}
				}
			}
		}
		for (i = 0; i < m * 6; i++) {
			for (j = 0; j < n * 9; j++) {
				printf("%c", b[i][j]);
			}
			printf("\n");
		}
	}
	else printf("Input Error\n");
}

int main()
{
	process();
	return 0;
}
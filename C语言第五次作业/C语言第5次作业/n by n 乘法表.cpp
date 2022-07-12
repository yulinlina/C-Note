#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

void process() {
	int n;
	scanf("%d", &n);
	int i,j = 1;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= i; j++) {
			printf("%d*%d=%d ", i, j, j * i);
		}
		printf("\n");
	}

}
int main()
{
	int num;
	int i;
	scanf("%d", &num);
	for (i = 0; i < num; i++)
	{
		process();
	}
	return 0;
}
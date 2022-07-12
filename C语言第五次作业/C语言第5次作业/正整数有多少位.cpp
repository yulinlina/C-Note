#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

void process() {
	int n;
	scanf("%d", &n);
	int count = 0;
	while (n) {
		count++;
		n /= 10;
	}
	printf("%d\n", count);
	
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
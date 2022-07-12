#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

void process()
{
	int n;
	scanf("%d", &n);
	int sum = 0;
	int flag = 1;
	int i = 0;
	while (n != 0) {
		int tmp = n % 10;
		if (tmp == 9) {
			printf("error");
			flag=0;
			break;
		}
		sum += tmp*pow(9,i);
		i++;
		n = n / 10;
	}
	if (flag) printf("%d\n", sum);
}
int main()
{
	int num;
	int l;
	scanf("%d", &num);
	for (l = 0; l < num; l++)
	{
		process();
	}
	return 0;
}
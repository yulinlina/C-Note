#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
void process() {
	int n;
	scanf("%d", &n);
	int i = 2;
	int j = 0;
	int count_2 = 0;
	int count_5 = 0;
	for (j = 2; j <= n; j++) {
		i = j;
		int flag = 0;
		while (i) {
			flag = 0;
			if (i % 2 == 0 &&i) {
				count_2++;
				i = i / 2;
				flag = 1;
			}
			if (i % 5 == 0 && i) {
				count_5++;
				i = i / 5;
				flag = 1;
			}
			if (flag == 0)
				break;
			
		}
	}
	int result = (count_5 <=count_2 ? count_5 : count_2);
	printf("%d\n", result);
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
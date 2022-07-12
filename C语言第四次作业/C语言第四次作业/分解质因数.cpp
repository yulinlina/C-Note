#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>

void process() {
	int n;
	scanf("%d", &n);
	for (int j = 2; j < n; j++) {
		for (size_t i = 2; i <= sqrt(n); i++) // 对于根号得加等于
		{
			if (n % i == 0) {
				n = n / i;
				printf("%d*", i);
				break;
			}
		}
	}
	
	printf("%d\n", n);

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
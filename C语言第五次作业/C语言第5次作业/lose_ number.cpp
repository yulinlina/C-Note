#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
void process() {
	int n;
	scanf("%d", &n);  // read number end with zero
	int count = 0;
	int sum = n;
	while (n) {
		scanf("%d", &n);
		sum += n;
		count++;
	}
	int t = count + 1;
	printf("%d\n", t * (t + 1) / 2 - sum);
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
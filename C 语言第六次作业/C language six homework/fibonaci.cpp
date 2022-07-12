#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
long long f(int n) {
	if (n == 1) return 1;
	if (n == 2) return 1;
	if (n == 3) return 1;  
	else 
		return (2*f(n - 1) + 3*f(n - 2)+5*f(n-3));
}
void process() {
	int n;
	long long result = 0;
	scanf("%d", &n);
	result = f(n);
	printf("%lld\n", result);
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
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
bool is_prime(int a) {
	if (a <= 1)
	{
		return false;
	}
	for (int j = 2; j < a / 2; j++)
	{

		if ((a % j) == 0)
		{
			return false;
		}
	}
	return true;
}
void process() {
	int n;
	scanf("%d", &n);
	int flag = 0;
	if (n % 2 == 1) printf("ERROR\n");
	int i = 2;
	int a = 0;
	for (i = 3; i<=(n / 2); i++) {
		if (is_prime(i)) {
			a = n - i;
			if (is_prime(a)) {
				printf("%d %d\n", i, a);
				flag = 1;
			}
		}
	}
	if (flag == 0)
		printf("ERROR\n");

}
int main()
{
	int i;
	process();
	return 0;
}
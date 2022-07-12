#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
void process()
{
	char a[50] = {0};
	char b[50] = {0};
	int c[60] = {0};
	scanf("%s", a);
	scanf("%s", b);
	int anum = strlen(a);
	int bnum = strlen(b);
	int i =(anum > bnum)? anum : bnum;
	int k = i;
	int carry = 0;
	while((bnum >0)&& (anum>0)) {
		c[i] = a[anum-1] + b[bnum-1] - 96 + carry;
		if (c[i] >= 10) {
			c[i] %= 10;
			carry = 1;
		}
		else carry = 0;
		i--;
		bnum--;
		anum--;
	}
	int j = anum;
	while (j>0) {
		c[i] = a[j-1] - 48+carry;
		if (c[i] >= 10) {
			c[i] %= 10;
			carry = 1;
		}
		else carry = 0;
		j--;
		i--;
	}
	j = bnum;
	while (j>0) {
		c[i] = b[j-1] - 48 + carry;
		if (c[i] >= 10) {
			c[i] %= 10;
			carry = 1;
		}
		else carry = 0;
		j--;
		i--;
	}
	i = 1;
	if (carry == 1) {
		c[0] = 1;
		i = 0;
	}
	for (j = i; j < k+1; j++) {
		printf("%d", c[j]);
	}
	printf("\n");
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
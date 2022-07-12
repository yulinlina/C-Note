#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#define PI 3
#define area(n) PI*n*n
#define abs(n) n>=0? n:-n
#define max(a,b) a>b?a:b
#define max_3(a,b,c) (a>b)&&(a>c)?a:((b>c)?b:c)
int main() {
	int a, b, c;
	scanf("%d", &a);
	printf("%d\n", area(a));
	scanf("%d", &a);
	printf("%d\n", abs(a));
	scanf("%d%d", &a,&b);
	printf("%d\n", max(a,b));
	scanf("%d%d%d", &a, &b,&c);
	printf("%d\n", max_3(a, b,c));
}
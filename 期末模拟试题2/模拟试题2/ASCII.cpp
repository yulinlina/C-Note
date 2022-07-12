#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
int to_ten(char c) {
	if ((c >= '0') && (c <= '9'))
		c = c - '0';
	else
		c = c - 'A' + 10;
	return c;
}
void process() {
	int i = 0; char c = 0;
	char a[100];
	scanf("%s", a);
	char num;
	while (a[i]) {
		num = to_ten(a[i])* 16 + to_ten(a[i+1]);
		printf("%c", num);
		i = i + 2;
	}
	printf("\n");
}
int main() {
	int n;
	scanf("%d", &n);
	int i = 0;
	for (i = 0; i < n; i++) {
		process();
	}
}
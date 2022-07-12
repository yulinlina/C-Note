#define _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<stdio.h>
#include <stdlib.h>
using namespace std;
int main() {
	int n, i; float sum = 0;
	cin >> n;
	int count = n;
	char str[100][5] = { 0 };
	int num[100] = { 0 };
	for (i = 0; i < n; i++) {
		cin >> str[i];
		if (str[i][0] == 'n') { num[i] = 0; count -= 1; }
		else  num[i] = atoi(str[i]);
		sum += num[i];
	}
	if (sum == 0) printf("n/a");
	else printf("%.2f", sum / count);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<iostream>
#include<algorithm>
using namespace std;
void Exchange(char* str[], int n) {
	char* temp;
	int i, j, k;
	for (i = 0; i < n - 1; i++) {
		k = i;
		for (j = i + 1; j < n; j++)
			if (strcmp(str[k], str[j]) > 0) k = j;
		if (k != i) {
			temp = str[i];
			str[i] = str[k];
			str[k] = temp;
		}
	}
}
int main() {
	int i;
	int n;
	scanf("%d", &n);
	char* str[100];
	char str_tmp[100][100] = { 0 };
	for (i = 0; i < n; i++) {
		scanf("%s", str_tmp[i]);  // 读字符串并传进指针数组
		str[i] = str_tmp[i];
	}
	Exchange(str,n);
	for (i = 0; i < n; i++) {
		printf("%s\n", str[i]);
	}
	return 0;
}
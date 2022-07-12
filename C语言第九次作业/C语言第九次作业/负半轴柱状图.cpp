#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<iostream>
using namespace std;
int main() {
	char str[30][5] = { 0 };
	int num[30] = { 0 };
	char graph[30] = { 0 };
	int n,i,j,max,row;
	int flag = 1; int rear = 0;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> str[i];
	}
	for (i = 0; i < n; i++) {
		rear = strlen(str[i]) - 1;
		if (isalpha(str[i][rear])) {
			graph[i] = str[i][rear]; 
			str[i][rear] = '\0'; 
			num[i] = atoi(str[i]);
		}
		else { 
			graph[i] = '+'; num[i] = atoi(str[i]); 
		}
	}
	max =num[0];
	for (i = 0; i < n; i++) {
		if(num[i]>max)max=num[i];
	}
	for (i = 0; i < max; i++) {
		for (j = 0; j < n; j++) {
			if (num[j] >= max - i) cout << graph[j]<<" ";
			else cout << "  ";
		}
		printf("\n");
	}
	for (j = 0; j < 2*n-1; j++)cout << "-";
	printf("\n");
	row = -1;
	flag = 1;
	while (flag) {
		flag = 0;
		for (j = 0; j < n; j++) {
			if (num[j] <= row) { cout << graph[j]<<" "; flag = 1; }
			else cout << "  ";
		}
		printf("\n");
		row--;
	}
	return 0;
}
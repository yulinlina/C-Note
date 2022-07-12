#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>

int disorder_count(char str[],int length) {
	int i = 0;
	int tmp = 0;
	int count = 0;
	int result = 0;
	for (tmp = 0; tmp < length - 1; tmp++) {
		for (i = tmp+1; i < length; i++) {
			result = str[tmp] - str[i];
			if (result > 0) count++;
		}
	}
	return count;
}
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(){
	
	char* str[150];
	int a[150] = { 0 };
	int min_label = 0;
	int min = a[min_label];
	char* temp;
	int flag = 1;
	while (scanf("%d%d", &n,&m) != EOF) {
		for (i = 0; i < m; i++) {
			cin >> s[i];
			a[i] = disorder_count(s[i], n);
			str[i] = s[i];
		}
		for (i = 0; i < m; i++) {
			for (j = m-1; j>i; j--) {
				if (a[j] < a[j - 1]) {
					swap(&a[j], &a[j - 1]);
					temp = str[j];
					str[j] = str[j - 1];
					str[j - 1] = temp;
				}
	
			}
		}
		for (i = 0; i < m; i++) {
			printf("%s\n", str[i]);
		}
		printf("********************\n");
	} 
	return 0;
}
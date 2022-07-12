#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
char up_to_low(char c) { // 大写转小写
	if ((c >= 'A') && (c <= 'Z')) {
		return (c + 32);
	}
	return c;
}
int main() {
	/*int n;
	scanf("%d", &n);*/
	char* str[100];
	int i = 0;
	int j = 0;
	char copy[100][20];
	char s='a';
	
	while (scanf("%s", copy[i]) != EOF) {
		j = 0;
		while (copy[i][j]) {
			copy[i][j] = up_to_low(copy[i][j]);
			j++;
		}
		str[i] = copy[i];
		printf("%s", str[i]);
		i++;
	}
	/*for (i = 0; s != '\n'; i++) {
		scanf("%s", copy[i]);
		str[i] = copy[i];
		s = getchar();
	}*/
	//int j = 0;
	//for (j = i-1; j>n-1; j--) { // 从最后一个开始移动
	//	str[j] = str[j -n];
	//}
	//for (j = 0; j < n; j++) {
	//	str[j] = copy[i-n+j];
	//}
	//if (n <= i) {
	//	for (j = 0; j < i; j++) {
	//		printf("%s ", str[j]);
	//	}
	//}
	//else printf("error");
}
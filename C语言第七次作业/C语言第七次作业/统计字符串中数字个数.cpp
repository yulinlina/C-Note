#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
bool is_number(char ch) {
	if ((ch>= 48) && (ch <= 57)) return true;
	else return false;
}
void process()
{
	char str[100] = { 0 };
	scanf("%s",str);
	int i =0;
	int count =0;
	for (i = 0; i < strlen(str); i++) {
		if (is_number(str[i])) {
			while (is_number(str[i + 1])){
				i++;
			}
			count++;
		}
	}
	printf("%d\n", count);
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
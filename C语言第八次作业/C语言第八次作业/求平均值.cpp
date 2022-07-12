#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
bool is_num(char c) {
	if ((c >= '0') && (c <= '9')) return true;
	return false;
}
void process()
{
	int m;
	int i=0;
	int j = 0;
	scanf("%d", &m);
	getchar();
	int flag = 0;
	char str[100] = { 0 };
	int a[100] = { 0 };
	float sum = 0;
	int end = 0;
	int beign = 0;
	int sign = 0;
	int length = 0;
	int count = 0;
	int tem_num = 0;
	gets(str);
	length = strlen(str);
	str[length] = ' ';
	while (str[i]) {
		if (str[i] == 'n') {
			count++;
			i += 4;
			beign = i;
			continue;
		}
		if (is_num(str[i])) {
			a[i] = str[i] - '0';
			flag = 1;
		}
		if (str[i] == '-') {
			sign = 1;
			beign = i + 1;
		}
		if (str[i+1]==' ') {
			end = i;
			length = end - beign + 1;
			for (j = 0; j < length; j++)
				tem_num=tem_num*10+a[beign + j];
			if (sign == 1) sum += -tem_num;
			else sum += tem_num;
			beign = end + 2;
			sign = 0;
			tem_num= 0;
		}
		i++;
		
	}
	if (flag == 0) printf("n/a\n");
	else printf("%.2f", sum / (m-count));


}
int main()
{
	process();
	return 0;

}
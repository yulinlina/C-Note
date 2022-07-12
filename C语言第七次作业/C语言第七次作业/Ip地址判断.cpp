#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
bool is_digit(int str) {
	if ((str >= 0) && (str <= 9))
		return true;
	else return false;
}
bool is_str(int str) {
	if ((str >= 49) && (str <= 75))
		return true;
	else return false;
	
}
void process()
{
	char str[50] = { 0 };
	gets_s(str);
	int a[30] = {0};
	int  j = 0;
	int is_stage = 0;
	int k = 0;
	int length;
	long num = 0;
	int flag = 1;
	int count = 0;
	while (strcmp(str, "End of file"))
	{
		for (j = 0; j < strlen(str); j++) {
			a[k] = str[k] - '0';
			if (is_str(a[k])) {
				flag = 0;
				break;
			}
			else if (is_digit(a[k])) {
				num = num * 10 + a[k];
					k++;
				is_stage++;
			}
			else if (str[k] == '.') {
				if ((num <= 255) && (num >=0)&&(is_stage>0)) { 
					count++;
					num = 0;
					k++;
					is_stage=0;
					
				}
				else {
					flag = 0; 
					break;
				}
			}
			else {
				flag = 0;
				break;
				}
			}
		if ((num <= 255) && (num >= 0) && (is_stage > 0)) {// 最后一个部分的判断
			num = 0;
		}
		else {
			flag = 0;
			num = 0;
		}
		if (count!=3)flag = 0;
		/*if (strcmp(str, "0.0.0.0") == 0)flag = 1;*/
		if (flag == 1) printf("YES\n");
		if (flag == 0) printf("NO\n");
		k = 0; // 存储数组置零
		is_stage = 0;// 判断置零
		count =0 ;// .置零
		gets_s(str);
		flag = 1;// 重置判断
	}
}

int main()
{
	process();
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<stdio.h>
using namespace std;
struct {
	char num[100];
	int val;
}dict[100] = {0};
extern int sum = 0;
bool is_char_num(char c) {
	if ((c <= '9') && (c >= '0'))return true;
	return false;
}
void hw_number(char str[]) {
	int i = 0; int flag = 1;
	char temp[1000]; 
	strcpy(temp, str);	// 与逆序比较
	reverse(str, str + strlen(str));
	if ((strcmp(temp, str) == 0)&&(strlen(str)>1)) { // 如果是回文数
		for (i = 0; i < sum; i++) { // 加入到字典
			if ((strcmp(dict[i].num, str) == 0)) {
				dict[i].val += 1;
				flag = 0;
			}
		}
		if (flag) {
			strcpy(dict[sum].num, str); dict[sum].val = 1;
			sum++;
		}
		flag = 1; // 如果出现在了字典中需要重置
	}
}
int main() {
	char list[10000] = { 0 }; char str[100] = {0};
	int i = 0; int begin_f = 1; int j = 0;
	while (scanf("%c", &list[i]) != EOF) i++;
	int begin = 0; int end = 0; i = 0;
	while (list[i]) {
		if ((is_char_num(list[i])) && (begin_f)&&(list[i]!='0')) {
			begin = i;
			begin_f = 0;
		}
		if ((is_char_num(list[i])) && (!is_char_num(list[i + 1])) ){ // 找到数字段 
			end = i; begin_f = 1;
			for(j =0;j<end-begin+1;j++)
				str[j]=list[begin+j];
			hw_number(str);
			memset(str,0,sizeof(str));
		}
		i++;
	}
	if (sum==0) cout<<"None";
	else { // 排序
		int max = dict[0].val;
		int order[50] = {0}; int total = 0;
		for (i = 0; i < sum; i++) {// 找出极大次数
			if (dict[i].val > max) max = dict[i].val;
		}
		for (i = 0; i < sum; i++) {  // 寻找所有出现次数极大的回文数
			if (dict[i].val == max) order[total++] = atoi(dict[i].num);
		}
		stable_sort(order, order + total); // 对回文数进行排序	
		for (i = 0; i < total; i++) cout << order[i] << " " << max << endl;
	}
}
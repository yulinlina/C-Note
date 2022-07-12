#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<string.h>
char up_to_low(char c) { // 大写转小写
	if ((c >= 'A') && (c <= 'Z')) {
		return (c+32);
	}
	return c;
}	
int main() {
	int i = 0;
	int j = 0;
	char* str_ptr[100];  // 用来储存每个单词
	int fre_array[100] = { 0 };//  用来存储每个单词出现的次数
	char vocabulary[100][15] = { 0 }; // 第一维是字母，第二维是这些字母组成的单词
	while (scanf("%s", vocabulary[i]) != EOF) {
		j = 0;
		while (vocabulary[i][j]) {   // 大写转小写
			vocabulary[i][j] = up_to_low(vocabulary[i][j]);
			j++;
		}
		i++;
	}
	int count = 0; // 统计所有单词
	count = i;
	for (i = 0; i < 100; i++)fre_array[i] = 1;
	int dic_count = 0;  // 统计没有重复出现的单词
	int sign = 1; // 标记为1，表示该单词未出现在str_ptr中
	for (i = 0; i < count; i++) {// 遍历所有单词
		for (j = 0; j < dic_count; j++) { // 对于该单词，比较其是否在str_ptr中出现
			if (strcmp(vocabulary[i], str_ptr[j]) == 0) { // 出现,则对应统计次数的频率+1
				fre_array[j] += 1;
				sign = 0;
			}
		}
		if (sign) { // 如果单词没有在str_ptr数组指向的单词中出现过，则str_ptr指针数组的当前指针指向该单词
			str_ptr[dic_count] = vocabulary[i];
			dic_count++;
		}
	}
	int max = 0;
	for (i = 1; i < dic_count; i++) {
		if ((fre_array[i] > fre_array[max])) max = i;
		if ((fre_array[i] == fre_array[max]) && (strcmp(str_ptr[i], str_ptr[max]) > 0)) max = i;
	}
	printf("%s %d", str_ptr[max], fre_array[max]);
	return 0;
}
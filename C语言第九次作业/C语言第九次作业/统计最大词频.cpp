#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<string.h>
char up_to_low(char c) { // ��дתСд
	if ((c >= 'A') && (c <= 'Z')) {
		return (c+32);
	}
	return c;
}	
int main() {
	int i = 0;
	int j = 0;
	char* str_ptr[100];  // ��������ÿ������
	int fre_array[100] = { 0 };//  �����洢ÿ�����ʳ��ֵĴ���
	char vocabulary[100][15] = { 0 }; // ��һά����ĸ���ڶ�ά����Щ��ĸ��ɵĵ���
	while (scanf("%s", vocabulary[i]) != EOF) {
		j = 0;
		while (vocabulary[i][j]) {   // ��дתСд
			vocabulary[i][j] = up_to_low(vocabulary[i][j]);
			j++;
		}
		i++;
	}
	int count = 0; // ͳ�����е���
	count = i;
	for (i = 0; i < 100; i++)fre_array[i] = 1;
	int dic_count = 0;  // ͳ��û���ظ����ֵĵ���
	int sign = 1; // ���Ϊ1����ʾ�õ���δ������str_ptr��
	for (i = 0; i < count; i++) {// �������е���
		for (j = 0; j < dic_count; j++) { // ���ڸõ��ʣ��Ƚ����Ƿ���str_ptr�г���
			if (strcmp(vocabulary[i], str_ptr[j]) == 0) { // ����,���Ӧͳ�ƴ�����Ƶ��+1
				fre_array[j] += 1;
				sign = 0;
			}
		}
		if (sign) { // �������û����str_ptr����ָ��ĵ����г��ֹ�����str_ptrָ������ĵ�ǰָ��ָ��õ���
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
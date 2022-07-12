//#define _CRT_SECURE_NO_WARNINGS 
//#include <stdio.h>
//#include<stdlib.h>
//#include<iostream>
//using namespace std;
//void process() {
//    char num[7][69] = 
//    {   {"*****      *  *****  *****  *   *  *****  *****  *****  *****  *****"},\
//        {"*   *      *      *      *  *   *  *      *          *  *   *  *   *"},\
//        {"*   *      *      *      *  *   *  *      *          *  *   *  *   *"},\
//        {"*   *      *  *****  *****  *****  *****  *****      *  *****  *****"},\
//        {"*   *      *  *          *      *      *  *   *      *  *   *      *"},\
//        {"*   *      *  *          *      *      *  *   *      *  *   *      *"},\
//        {"*****      *  *****  *****      *  *****  *****      *  *****  *****"} };
//    int i = 0;
//    int j = 0;
//    int k = 0;
//    char str[5] = { 0 };
//    cin >> str;cout << str;
//    printf(":\n");
//    for (i = 0; i < 7; i++) {
//        for (k = 0; k < strlen(str); k++) { // 对于字符串中的每个数
//            for (j = (str[k] - '0')*7; j < (str[k] - '0') * 7+ 5; j++) {// 打印对应的数字
//                printf("%c", num[i][j]);
//            }
//            printf("  ");
//        }
//        printf("\n");
//    }
//}
//int main()
//{
//    int n;
//    int i;
//    scanf("%d", &n);
//    getchar();// 读入回车符
//    for (i = 0; i < n; i++)
//    {
//        process();
//    }
//    return 0;
//
#include<stdio.h>
#include"text_helper.h"
int main() {
	hello();
	return 0;
}
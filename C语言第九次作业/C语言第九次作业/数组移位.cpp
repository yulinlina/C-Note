#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
//函数实现
void NumberMov(int* data, int m,int n)
{
    int b[100] = { 0 };
    int i = 0;
    for (i = 0; i < m; i++) {
        b[i] = *(data + n-1 - i);
    }
    for (i = n-1; i >=m; i--) {
        *(data + i) = *(data + i - m);
    }
    for (i = 0; i < m; i++) {
        *(data + i) = b[m-1-i];
    }
}
int main()
{
    int n;
    int i;
    scanf("%d", &n);
    int a[100] = { 0 };
    int m;
    for (i = 0; i < n;i++)
    {
        scanf("%d", a + i);
    }
    scanf("%d", &m);
    NumberMov(a, m,n);//函数调用
    for (i = 0; i < n; i++) {
       printf("%d ", *(a+i));
    }
    return 0;
}

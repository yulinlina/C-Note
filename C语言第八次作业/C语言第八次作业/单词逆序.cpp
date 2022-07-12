#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
bool is_str(char c) {
    if (((c < 'z') && (c > 'a'))||((c>'A')&&(c<'Z'))) return true;
    else return false;
}
void process() {
    char a[100] = { 0 };
    char b[100] = { 0 };
    int begin = 0;
    int end;
    int i = 0;
    int length;
    int j;
    gets(a);
    while(a[i]) {
        b[i] = a[i];
        if (!is_str(a[i+1])) {  // 只要不是字母就进行分割
            end = i;
            length = end - begin + 1;
            for (j = 0; j < length; j++) {
                b[begin + j] = a[end - j]; // 可以考虑倒着打印?
            }
            b[end + 1] = ' ';
            begin = end + 2;
        }
        i++;
    }
    for (j = 0; j < i; j++) {
        printf("%c", b[j]);
    }
 
}
int main()
{
    process();
    return 0;
}

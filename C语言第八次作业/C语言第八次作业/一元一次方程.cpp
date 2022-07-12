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
void process() {
    char str[100] = { 0 };
    gets_s(str);
    char name;
    int equal = 0;
    int i = 0;
    int sign = 0;
    int temp = 0;
    float total_x = 0;
    float total_v = 0;
    int length = strlen(str);
    int flag = 0;
    for (i = 0; i < length; i++) {   //寻找到未知变量
        if (str[i] == '=') flag = 1;
        if ((str[i] >= 'a') && (str[i]) <= 'z') {
            name = str[i];
            break;
        }
    }
    i = 0;
    while (i<=length) {
        if (str[i] == '=') equal = 1;
        if (is_num(str[i])) {
            sign = i - 1;
            while (is_num(str[i])) {  
                temp = temp * 10 + str[i] - '0';
                i++;
            }
            i -= 1;
            if((sign >=0) && (str[sign] == '-')) {
                temp = -temp;
            }

        }
        if (str[i+1] == name)
            total_x += pow(-1, equal) * temp;
        else
        {
            total_v+= pow(-1, equal+1) * temp;
        }
        if ((str[i+1] == name)&&(str[i]=='-')) total_x += pow(-1, equal+1);
        i++;
        temp = 0;
    }
    if (total_x == 0) total_x = pow(-1,flag);
    printf("%c=%.6f\n", name, total_v / total_x);
}
int main()
{
    int n;
    int i;
    scanf("%d", &n);
    getchar();
    for (i = 0; i < n; i++)
    {
        process();
    }
    return 0;
}
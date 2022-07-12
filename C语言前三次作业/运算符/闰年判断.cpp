#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool even(int year)
{
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        return true;
    else
        return false;
}
int main() {
    int n, i, year;
    scanf("%d", &n);  // 有n组数据
    for (i = 0; i < n; i++)
    {
        scanf("%d", &year);
        fflush(stdin);
        if (year > 0 && even(year)) {
            printf("yes\n");
            fflush(stdout);
        }
        else
            printf("no\n");

    }

	return 0;
}

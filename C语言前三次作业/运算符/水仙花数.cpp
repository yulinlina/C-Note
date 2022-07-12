#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

int main() {

    int n, i, a, b;
    scanf("%d", &n);  // 有n组数据

    for (i = 0; i < n; i++)
    {
        int x, y, z, m;
        int count = 0;
        scanf("%d%d", &a, &b); 
        fflush(stdin);// 读入两个整数
        int arr[10] = { 0 };
        for (int i = a; i <= b; i++)
        {
            x = i % 10;
            y = (i % 100 - x) / 10;
            z = (i - x - y * 10) / 100;
            m = x * x * x + y * y * y + z * z * z;
            if (i == m)
            {
                arr[count] = i;
                count++;
            }
        }
        fflush(stdout);
        if (count == 0)
        {
            printf("%d\n",-1);
            continue;
        }
        else
        {
            for (int i = 0; i < count; i++)
                printf("%d ", arr[i]);
            continue;
        }

    }
 return 0;

}
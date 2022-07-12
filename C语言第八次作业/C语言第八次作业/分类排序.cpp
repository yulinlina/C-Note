#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<algorithm>
using namespace std;
void process()
{
    int a[100] = { 0 };
    int odd[100] = { 0 };
    int even[100] = { 0 };
    int num = 0;
    int count_odd = 0;
    int count_even = 0;
    scanf("%d", &num);
    int i = 0;
    for (i = 0; i < num; i++) {
        scanf("%d", &a[i]);
    }
    for (i = 0; i < num; i++) {
        if (a[i] % 2 == 0) {
            even[count_even] = a[i];
            count_even++;
        }
        if (a[i] % 2 == 1) {
            odd[count_odd] = a[i];
            count_odd++;
        }
    }
    stable_sort(odd, odd + count_odd);
    stable_sort(even,even+count_even);
    for (i = 0; i < count_odd; i++) {
        printf("%d ", odd[i]);
    }
    for (i = 0; i < count_even; i++) {
        printf("%d ", even[i]);
    }
    printf("\n");
    
}
int main()
{
    int n;
    int i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        process();
    }
    return 0;
}
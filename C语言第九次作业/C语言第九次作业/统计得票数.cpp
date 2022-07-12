#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
struct person
{

    char name[20];

    int count;

}leader[3] = { "Li", 0, "Zhang", 0, "Fun", 0};
void process() {
    char str[10] = { 0 };
    scanf("%s", &str);
    int i = 0;
    for (i = 0; i < 3; i++) {
        if (strcmp(str, leader[i].name) == 0)
            leader[i].count++;
    }
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
    for (i = 0; i < 3; i++) {
        printf("%s:%d\n", leader[i].name, leader[i].count);
    }
    return 0;
}
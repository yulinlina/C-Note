#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
enum WEEKDAY {
    MONDAY = 1,
    TUSEDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};
int main() {
  
	int n;
	scanf("%d", &n);
	int i = 0;
    int m;
    enum WEEKDAY day;
    char s[][10] = {"MONDAY","TUSEDAY","WEDNESDAY","THURSDAY","FRIDAY","SATURDAY","SUNDAY"};
	for (i = 0; i < n; i++) {
        scanf("%d", &m);
        printf("%s\n",s[m-1]);
	}
}
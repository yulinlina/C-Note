#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>
using namespace std;
void process(int n,int w) {
	int a[100] = { 0 };
	int i = 0;
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
    int half = (w - 1) / 2;
    int begin = 0;  // (w - 1) / 2;
	int b[100] = { 0 };
	int c[10] = { 0 };
    int mid=0;
	for (i = 0; i < half; i++) {
		b[i] = a[i];
		b[n - half + i] = a[n - half + i];
	}
    //printf("%d%d", n, w);
    while (begin <= n - w)// ×î´óÂË²¨±ß½ç
    {
        for (i = 0; i < w; i++) {
            c[i] = a[begin + i];
        }
        //QuickSort(c, 0, w - 1);
        stable_sort(c, c + w - 1);
        mid =(begin + begin + w - 1)/2;
        b[mid] = c[half];
        begin++;
    }
    for (i = 0; i < n; i++) {
        printf("%d ", b[i]);
  }
    printf("\n");
}
int main() {
	int w;
	int n;
    while ((scanf("%d%d", &w, &n))!=EOF) {
        if (w % 2 == 0)printf("ERROR\n");
        else
            process(n, w);
    }
	return 0;
}
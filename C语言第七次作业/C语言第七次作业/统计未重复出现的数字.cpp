#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
void Swap(int* p, int* q)
{
	int buf;
	buf = *p;
	*p = *q;
	*q = buf;
}
void QuickSort(int* a, int low, int high)
{
    int i = low;
    int j = high;
    int key = a[low];
    if (low >= high) //如果low >= high说明排序结束了
    {
        return;
    }

    while (low < high) //该while循环结束一次表示比较了一轮
    {
        while (low < high && key <= a[high])
        {
            --high; //向前寻找
        }
        if (key > a[high])
        {
            Swap(&a[low], &a[high]);
            ++low;
        }
        while (low < high && key >= a[low])
        {
            ++low; //向后寻找
        }
        if (key < a[low])
        {
            Swap(&a[low], &a[high]);
            --high;
        }
    }
    QuickSort(a, i, low - 1); //用同样的方式对分出来的左边的部分进行同上的做法
    QuickSort(a, low + 1, j); //用同样的方式对分出来的右边的部分进行同上的做法
}
void process()
{
	int num;
	int i = 0;
	scanf("%d", &num);
	int a[100] = { 0 };
	for (i = 0; i < num; i++) {
		scanf("%d", &a[i]);
	}
    QuickSort(a, 0, num - 1);
    /*for (i = 0; i < num; i++) {
        printf("%d ", a[i]);
    }*/
    int count = 1;
    for (i = 1; i < num; i++) {
        if (a[i] != a[i - 1])
            count++;
    }
    printf("%d\n", count);

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
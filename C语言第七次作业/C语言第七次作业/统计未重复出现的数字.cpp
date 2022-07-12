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
    if (low >= high) //���low >= high˵�����������
    {
        return;
    }

    while (low < high) //��whileѭ������һ�α�ʾ�Ƚ���һ��
    {
        while (low < high && key <= a[high])
        {
            --high; //��ǰѰ��
        }
        if (key > a[high])
        {
            Swap(&a[low], &a[high]);
            ++low;
        }
        while (low < high && key >= a[low])
        {
            ++low; //���Ѱ��
        }
        if (key < a[low])
        {
            Swap(&a[low], &a[high]);
            --high;
        }
    }
    QuickSort(a, i, low - 1); //��ͬ���ķ�ʽ�Էֳ�������ߵĲ��ֽ���ͬ�ϵ�����
    QuickSort(a, low + 1, j); //��ͬ���ķ�ʽ�Էֳ������ұߵĲ��ֽ���ͬ�ϵ�����
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
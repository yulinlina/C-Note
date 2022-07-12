//#define _CRT_SECURE_NO_WARNINGS 
//#include <stdio.h>
//#include<stdlib.h>
//#include<math.h>
//#include<string.h>
//#include<stdbool.h>
#include<iostream>
using namespace std;
typedef struct Node {
	int data;
	struct Node* pnext;
}NODE,*pNode;
pNode CreateList(int n) { // ͷ�巨
	int i;
	int data=0;
	pNode phead = NULL, pnew = NULL;
	for (i = 0; i < n; i++) {
		pnew = (pNode)malloc(sizeof(NODE));
		scanf("%d", &data);
		if (pnew != NULL) {
			pnew->data = data;
			pnew->pnext = phead;
			phead = pnew;
		}
	}
	return phead;
}
void Insert_rear(&NODE, int item) {
	pNode pnew;
	pnew = (pNode)malloc(sizeof(NODE));
	if (pnew == NULL) {
		printf("FAIL TO ALLOCATE MEMORT");
		return;
	}
}
void PrintList(pNode p,int pos) {
	int i = 0;
	for(i=0;i<pos-1;i++)p = p->pnext;
	printf("%d\n", p->data);
	
}
void buble_sort(pNode p ,int n) {
	int i = 0;
	int j = 0;
	int temp = p->data;
	pNode tmp = p;
	for (i = 0; i < n; i++) {
		for (j =0; j < n-i-1; j++) {
			if (p->data>= p->pnext->data) {
				temp = p->data;
				p->data = p->pnext->data;
				p->pnext->data = temp;
			}
			p = p->pnext;
		}
		p = tmp;
	}
}
int main() {
	int n;
	scanf("%d", &n);
	pNode head = CreateList(n);
	buble_sort(head, n);
	scanf("%d", &n);
	PrintList(head,n);
	return 0;
	
}
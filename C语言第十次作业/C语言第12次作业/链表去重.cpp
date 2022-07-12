#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
typedef struct _student {

    char name[10];

    char stuNum[20];

    struct _student* pnext;
	//struct _student* pre=NULL;
} NODE,*pNode;
pNode CreateList(int n) { // 尾插法
	int i;
	int flag = 1;
	pNode last = NULL, pnew = NULL,phead=NULL;
	for (i = 0; i < n; i++) {
		pnew = (pNode)malloc(sizeof(NODE));
		scanf("%s", pnew->name);
		scanf("%s", pnew->stuNum);
		if (flag) { // 创建头结点
			phead = pnew;
			last = pnew;
			last->pnext = NULL;
			flag = 0;
		}
		else
		{
			if (pnew != NULL) {
				pnew->pnext = NULL;
				last->pnext = pnew;
				last = pnew;
			}
		}
		
	}
	return phead;
}
pNode duplicate(pNode p) {
	//pNode head = p;
	pNode tmp = p;
	while(tmp!=NULL){
		while(p->pnext!=NULL) {
			if (strcmp(tmp->stuNum, p->pnext->stuNum) == 0) {
				p->pnext = p->pnext->pnext;
			}
			else
				p = p->pnext;
		}
		tmp = tmp->pnext;
	}
	return p;
}
void PrintList(pNode p, int pos) {
	int i = 0;
	//for (i = 0; i < pos; i++)p = p->pnext;
	while (p!=NULL)
	{
		printf("%s %s\n", p->name, p->stuNum);
		p = p->pnext;
	}
	
}
int main() {
	int n;
	scanf("%d", &n);
	pNode head = CreateList(n);
	duplicate(head);
	PrintList(head, n);
}


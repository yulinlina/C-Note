// Easy.x start.cpp : ���ļ����� "main" ����������ִ�н��ڴ˴���ʼ��������
//
#include <iostream>
#include<graphics.h>
#include<conio.h>
#define W 350
#define H 600
IMAGE img_bk;
int main() {
	initgraph(W, H);
	loadimage(&img_bk, "..\\data\\backgrd.png");
	putimage(0, 0, &img_bk);
	_getch();
	closegraph;
	return 0;
}
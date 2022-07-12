// Easy.x start.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
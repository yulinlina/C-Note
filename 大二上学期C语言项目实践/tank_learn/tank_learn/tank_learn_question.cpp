#define _CRT_SECURE_NO_DEPRECATE
#include <graphics.h>
#include <conio.h>
#include<Windows.h>
#include<stdio.h>
#include<iostream>
#include <time.h>
#include <MMSystem.h>
#include<iostream>
#include<sstream>
#pragma comment(lib,"winmm.lib") //导入声音库
using namespace std;
extern bool flag;			//主标志
extern bool Flag1 = 1, Flag2 = 1;	//总体标志
extern bool flag1 = 2, flag2 = 1;	//死亡标志
extern int map[26][26]= {
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0 },
	{ 0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0 },
	{ 0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0 },
	{ 0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0 },
	{ 0,0,1,1,0,0,1,1,0,0,1,1,2,2,1,1,0,0,1,1,0,0,1,1,0,0 },
	{ 0,0,1,1,0,0,1,1,0,0,1,1,2,2,1,1,0,0,1,1,0,0,1,1,0,0 },
	{ 0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0 },
	{ 0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0 },
	{ 0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0 },
	{ 1,1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,1,1 },
	{ 2,2,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,2,2 },
	{ 0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,1,1,0,0,1,1,0,0,1,1,1,1,1,1,0,0,1,1,0,0,1,1,0,0 },
	{ 0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0 },
	{ 0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0 },
	{ 0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0,1,1,0,0 },
	{ 0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0 },
	{ 0,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,1,1,0,0,1,1,0,0 },
	{ 0,0,1,1,0,0,1,1,0,0,0,1,1,1,1,0,0,0,1,1,0,0,1,1,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,1,3,4,1,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,1,4,4,1,0,0,0,0,0,0,0,0,0,0,0 }
};	//地图
extern int storefile;		//存档
extern int mapCopy[26][26];	//原始地图
extern int times = 0;                            //记录当前程序的休眠次数
extern int enemyTotal = 3;	//敌人此时的数量
extern int enemyAlive = 5;	//敌人活着的
/*
########################################
需要添加模式选择
*/
TCHAR s[] = _T("存档失败");
TCHAR s2[] = _T("读档失败");
void enemy_param_store() {
	FILE* fp = fopen("enemy.txt", "wb+ ");
	if (fp == NULL) {
		settextcolor(RED);
		settextstyle(300, 70, _T("微软雅黑"));
		outtextxy(10, 20, s);
	}
	else {
		fwrite(&enemyTotal, sizeof(enemyTotal), 1, fp);
		fwrite(&enemyAlive, sizeof(enemyAlive), 1, fp);
		fclose(fp);
	}
}
void enemy_param_read() {
	FILE* fp = fopen("enemy.txt", "rb+ ");
	if (fp == NULL) {
		settextcolor(RED);
		settextstyle(300, 70, _T("微软雅黑"));
		outtextxy(10, 20, s2);
	}
	else {
		fread(&enemyTotal, sizeof(enemyTotal), 1, fp);
		fread(&enemyAlive, sizeof(enemyAlive), 1, fp);
		fclose(fp);
	}
}
extern int Single = 2;		//单人 or 双人模式
extern enum DIRECTION		//方向
{
	UP, DOWN, LEFT, RIGHT
};
extern struct TANK			//坦克
{
	int tank_x;
	int tank_y;
	int direction;          //判断坦克方向，从而确定子弹的飞行轨迹    1 为上 ，2为下 ， 3为左， 4为右
	int state;
};
struct TANK myTankMove1 = {8,24,LEFT,true };

extern struct BULLET		//子弹
{
	int bullet_x;
	int bullet_y;
	DIRECTION direction;
	int state;
};
struct BULLET myBulletMove1;

void map_store() {
	FILE* fp = fopen("map.txt", "wb+ ");
	if (fp == NULL) {
	 settextcolor(RED);
	settextstyle(300, 70, _T("微软雅黑"));
	outtextxy(10, 20, s);
	}
	else {
		fwrite(&map, sizeof(map), 1, fp);
		fclose(fp);
	}
}
void my_bullet_store() {
	FILE* fp = fopen("bullet.txt", "wb+ ");
	if (fp == NULL)outtextxy(10, 20, s);
	else {
		fwrite(&myBulletMove1, sizeof(myBulletMove1), 1, fp);
		fclose(fp);
	}
}
void my_bullet_read() {
	FILE* fp = fopen("bullet.txt", "rb+ ");
	if (fp == NULL) outtextxy(10, 20, s2);
	else {
		fread(&myBulletMove1, sizeof(myBulletMove1), 1, fp);
		//printf("%d", myTankMove1.tank_x); 验证读档
	}
}
void map_read() {
	int i, j;
	FILE* fp = fopen("map.txt", "rb+ ");
	if (fp == NULL) outtextxy(10, 20, s2);
	else {
		fread(&map, sizeof(map), 1, fp);
		/*for (i = 0; i < 26; i++) {  打印查看是否读档成功
			for (j = 0; j < 26; j++) {
				printf("%d ",map[i][j]);
			}
		}*/
		fclose(fp);;
	}
}
void my_tank_store() {
	FILE* fp = fopen("TANK.txt", "wb+ ");
	if (fp == NULL) outtextxy(10, 20, s);
	else {
		fwrite(&myTankMove1, sizeof(myTankMove1), 1, fp);
		fclose(fp);
	}
}
void my_tank_read() {
	FILE* fp = fopen("TANK.txt", "rb+ ");
	if (fp == NULL)outtextxy(10, 20, s2);
	else {
		fread(&myTankMove1, sizeof(myTankMove1), 1, fp);
		//printf("%d", myTankMove1.tank_x); 验证读档
	}
}
void  StoreFile() {
	map_store();
	my_tank_store();
	my_bullet_store();
}

void LoadFile() {
	map_read();
	my_tank_read();
	my_bullet_read();
	 
}
// 主函数
int main()
{
	int i = 5;
	string file = "record";
	stringstream fmt;
	fmt << file << i;
	string targetfile = fmt.str();
	cout << targetfile; // 格式化字符串


	/*enemy_param_store();
	enemy_param_read();*/
	/*StoreFile();
	LoadFile();*/
	//map_store();
	//map_read();
	//StoreFile();
	//LoadFile();
	// 绘图窗口初始化
	//initgraph(640, 480);
	////load_img();
	//// 按任意键退出
	//_getch();
	//closegraph();
	return 0;
}
//void load_img() {
//	// 读取图片至绘图窗口
//	IMAGE img;
//	loadimage(&img, _T("logo"));
//	putimage(320, 240, &img);
//}
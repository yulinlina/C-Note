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
#pragma comment(lib,"winmm.lib") //����������
using namespace std;
extern bool flag;			//����־
extern bool Flag1 = 1, Flag2 = 1;	//�����־
extern bool flag1 = 2, flag2 = 1;	//������־
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
};	//��ͼ
extern int storefile;		//�浵
extern int mapCopy[26][26];	//ԭʼ��ͼ
extern int times = 0;                            //��¼��ǰ��������ߴ���
extern int enemyTotal = 3;	//���˴�ʱ������
extern int enemyAlive = 5;	//���˻��ŵ�
/*
########################################
��Ҫ���ģʽѡ��
*/
TCHAR s[] = _T("�浵ʧ��");
TCHAR s2[] = _T("����ʧ��");
void enemy_param_store() {
	FILE* fp = fopen("enemy.txt", "wb+ ");
	if (fp == NULL) {
		settextcolor(RED);
		settextstyle(300, 70, _T("΢���ź�"));
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
		settextstyle(300, 70, _T("΢���ź�"));
		outtextxy(10, 20, s2);
	}
	else {
		fread(&enemyTotal, sizeof(enemyTotal), 1, fp);
		fread(&enemyAlive, sizeof(enemyAlive), 1, fp);
		fclose(fp);
	}
}
extern int Single = 2;		//���� or ˫��ģʽ
extern enum DIRECTION		//����
{
	UP, DOWN, LEFT, RIGHT
};
extern struct TANK			//̹��
{
	int tank_x;
	int tank_y;
	int direction;          //�ж�̹�˷��򣬴Ӷ�ȷ���ӵ��ķ��й켣    1 Ϊ�� ��2Ϊ�� �� 3Ϊ�� 4Ϊ��
	int state;
};
struct TANK myTankMove1 = {8,24,LEFT,true };

extern struct BULLET		//�ӵ�
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
	settextstyle(300, 70, _T("΢���ź�"));
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
		//printf("%d", myTankMove1.tank_x); ��֤����
	}
}
void map_read() {
	int i, j;
	FILE* fp = fopen("map.txt", "rb+ ");
	if (fp == NULL) outtextxy(10, 20, s2);
	else {
		fread(&map, sizeof(map), 1, fp);
		/*for (i = 0; i < 26; i++) {  ��ӡ�鿴�Ƿ�����ɹ�
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
		//printf("%d", myTankMove1.tank_x); ��֤����
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
// ������
int main()
{
	int i = 5;
	string file = "record";
	stringstream fmt;
	fmt << file << i;
	string targetfile = fmt.str();
	cout << targetfile; // ��ʽ���ַ���


	/*enemy_param_store();
	enemy_param_read();*/
	/*StoreFile();
	LoadFile();*/
	//map_store();
	//map_read();
	//StoreFile();
	//LoadFile();
	// ��ͼ���ڳ�ʼ��
	//initgraph(640, 480);
	////load_img();
	//// ��������˳�
	//_getch();
	//closegraph();
	return 0;
}
//void load_img() {
//	// ��ȡͼƬ����ͼ����
//	IMAGE img;
//	loadimage(&img, _T("logo"));
//	putimage(320, 240, &img);
//}
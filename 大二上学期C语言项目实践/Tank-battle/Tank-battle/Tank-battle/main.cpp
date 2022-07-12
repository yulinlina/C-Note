#include <graphics.h>         //����easyXͼ�ο�
#include <Windows.h> 
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <MMSystem.h>
#pragma comment(lib,"winmm.lib")           //����������

#define ENENMY_TANK_NUMBER 10
bool flag = 1;
enum DIRECTION { UP, DOWN, LEFT, RIGHT };        //̹�˵ķ���
	  //̹�˽ṹ��

struct TANK
{
	int tank_x;
	int tank_y;
	int direction;          //�ж�̹�˷��򣬴Ӷ�ȷ���ӵ��ķ��й켣    1 Ϊ�� ��2Ϊ�� �� 3Ϊ�� 4Ϊ��
	bool state;
};
//�ӵ��ṹ��
struct BULLET
{
	int bullet_x;
	int bullet_y;
	DIRECTION direction;
	bool state;
};
//0 Ϊ�� 1Ϊ������ǽ  2Ϊ��������ǽ  3��4Ϊ�ϼ�
int map[26][26] = {
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
};

//*******************  ��Ϸ�׽���   **********************
void outputPage1()
{
	IMAGE logoImg;
	loadimage(&logoImg, _T("logo.bmp"), 433, 147);
	putimage(113, 40, &logoImg);

	IMAGE illustrate;
	loadimage(&illustrate, _T("illustrate.jpg"), 300, 300);
	settextcolor(RGB(255, 255, 255));
	settextstyle(30, 0, _T("΢���ź�"));
	rectangle(195, 200, 275, 240);
	rectangle(375, 200, 455, 240);
	outtextxy(210, 205, _T("˵ ��"));
	outtextxy(390, 205, _T("�� ʼ"));

	//****************  �������¼�  *********************
	MOUSEMSG m;
	while (1)
	{
		m = GetMouseMsg();
		switch (m.uMsg)
		{
		case WM_MOUSEMOVE:
			if ((m.x >= 195 && m.x <= 275) && (m.y >= 200 && m.y <= 240))
			{
				putimage(150, 250, &illustrate);
			}
			else
			{
				setfillcolor(BLACK);
				solidrectangle(150, 250, 450, 550);
			}
			break;

		case WM_LBUTTONDOWN:
			if ((m.x >= 375 && m.x <= 455) && (m.y >= 200 && m.y <= 240))
			{
				cleardevice();
				return;
			}
			break;

		}

	}

}

//***************** ��Ϸ��ʼ������ ****************
void outputPage2()
{
	IMAGE brick1;
	IMAGE brick2;
	IMAGE home;
	loadimage(&home, _T("home.jpg"), 50, 50);
	loadimage(&brick1, _T("wall1.jpg"), 25, 25);
	loadimage(&brick2, _T("wall2.jpg"), 25, 25);
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			switch (map[i][j])
			{
			case 1:putimage(25 * j, 25 * i, &brick1); break;
			case 2:putimage(25 * j, 25 * i, &brick2); break;
			case 3:
				putimage(25 * j, 25 * i, &home);
				map[i][j] = 4;
				break;
			}
		}
	}
	return;
}
//********** �޸ĵ�ͼ����������� ************   // ���ɣ�
void map_par(TANK* tank, int n)
{
	map[tank->tank_y][tank->tank_x] = n;
	map[tank->tank_y + 1][tank->tank_x] = n;
	map[tank->tank_y][tank->tank_x + 1] = n;
	map[tank->tank_y + 1][tank->tank_x + 1] = n;
}
//***************  ̹���ƶ�  *****************
int tankMove(TANK* tank, DIRECTION direction, IMAGE* img, int n)
{
	map_par(tank, 0);
	setfillcolor(BLACK);
	solidrectangle(tank->tank_x * 25, tank->tank_y * 25, tank->tank_x * 25 + 50, tank->tank_y * 25 + 50);  //����̹��ԭ��λ��
	if (direction == UP)
	{
		tank->tank_y--;
	}
	else if (direction == DOWN)
	{
		tank->tank_y++;
	}
	else if (direction == LEFT)
	{
		tank->tank_x--;
	}
	else if (direction == RIGHT)
	{
		tank->tank_x++;
	}
	else
	{
		return 0;
	}
	map_par(tank, n);
	putimage(tank->tank_x * 25, tank->tank_y * 25, img);              //���̹���ƶ���λ��

}

// *****************************   ʹ�з�̹�˳���Ŀ��ķ���ǰ�� *********************
DIRECTION enemyMove(TANK* Etank, int x, int y)
{
	int r = rand() % 100;
	if (y < Etank->tank_y)
	{
		if (x < Etank->tank_x)
		{
			if (r < 50)
				return UP;
			else
				return LEFT;
		}
		else if (x > Etank->tank_x)
		{
			if (r < 50)
				return UP;
			else
				return RIGHT;
		}
		else if (x == Etank->tank_x)
		{
			if (map[Etank->tank_y - 1][Etank->tank_x] == 2)
			{
				if (r < 50)
					return LEFT;
				else
					return RIGHT;
			}
			return UP;
		}
	}
	else if (y > Etank->tank_y)
	{
		if (x < Etank->tank_x)
		{
			if (r < 50)
				return DOWN;
			else
				return LEFT;
		}
		else if (x > Etank->tank_x)
		{
			if (r < 50)
				return DOWN;
			else
				return RIGHT;
		}
		else if (x == Etank->tank_x)
		{
			if (map[Etank->tank_y + 2][Etank->tank_x] == 2)
			{
				if (r < 50)
					return LEFT;
				else
					return RIGHT;
			}
			return DOWN;
		}
	}
	else if (y == Etank->tank_y)
	{
		if (x < Etank->tank_x)
			return LEFT;
		else
			return RIGHT;
	}
}

//**********************  ��Ϸ���� ********************
void putGameOver()
{
	IMAGE gameOver;
	loadimage(&gameOver, _T("gameover.jpg"), 600, 400);
	for (int i = 0; i < 130; i++)
	{
		cleardevice();
		putimage(25, i, &gameOver);
		Sleep(15);
	}
	system("pause");

}
void victory()
{
	cleardevice();
	settextcolor(RED);
	settextstyle(300, 70, _T("΢���ź�"));
	outtextxy(80, 150, _T("Victory"));
}
void tankFire(TANK* tank, BULLET* bullet, bool need)
{
	if (bullet->state == 0)          //̹��״̬Ϊ0�����ӵ��Ѳ����ڣ������ٴ����
	{
		if (need)
		{
			PlaySound(_T("boom.wav"), NULL, SND_FILENAME | SND_ASYNC);
		}
		switch (tank->direction)
		{
		case UP:
			bullet->bullet_x = tank->tank_x * 25 + 25;
			bullet->bullet_y = tank->tank_y * 25 - 3;
			break;
		case DOWN:
			bullet->bullet_x = tank->tank_x * 25 + 25;
			bullet->bullet_y = tank->tank_y * 25 + 53;
			break;
		case LEFT:
			bullet->bullet_x = tank->tank_x * 25 - 3;
			bullet->bullet_y = tank->tank_y * 25 + 25;
			break;
		case RIGHT:
			bullet->bullet_x = tank->tank_x * 25 + 53;
			bullet->bullet_y = tank->tank_y * 25 + 25;
			break;

		}
		bullet->state = 1;
		bullet->direction = DIRECTION(tank->direction);
	}
}
void putTankBoom(int x, int y)   // ����̹�˱�ը ͼ��
{
	IMAGE img[8];
	/* char name[32];
	   for (int i = 0; i < 8; i++)
	   {
		   sprintf_s(name, 32, "blast%d.gif", i + i);
		   loadimage(&img[i], name, 50, 50);
	   }     */
	loadimage(&img[0], _T("blast1.gif"), 50, 50);
	loadimage(&img[1], _T("blast2.gif"), 50, 50);
	loadimage(&img[2], _T("blast3.gif"), 50, 50);
	loadimage(&img[3], _T("blast4.gif"), 50, 50);
	loadimage(&img[4], _T("blast5.gif"), 50, 50);
	loadimage(&img[5], _T("blast6.gif"), 50, 50);
	loadimage(&img[6], _T("blast7.gif"), 50, 50);
	loadimage(&img[7], _T("blast8.gif"), 50, 50);
	for (int i = 0; i < 8; i++)
	{
		putimage(x * 25, y * 25, &img[i]);
		Sleep(10);
	}
}
//  ***************************  ���ӵ�������ײ���  **************************  // ��ʱû������
void  bulletMove(BULLET* bullet, bool& flag, int tell, TANK* tank, int& enemyAlive)
{
	IMAGE Wall2;
	loadimage(&Wall2, _T("wall2.jpg"), 25, 25);
	setfillcolor(BLACK);
	solidcircle(bullet->bullet_x, bullet->bullet_y, 2);
	int x1, y1, x2, y2;
	x1 = bullet->bullet_x / 25;
	y1 = bullet->bullet_y / 25;
	switch (bullet->direction)              //�ж��ӵ�����
	{
	case UP:
		bullet->bullet_y -= 3;
		x2 = x1 - 1;
		y2 = y1;
		break;
	case DOWN:
		bullet->bullet_y += 3;
		x2 = x1 - 1;
		y2 = y1;
		break;
	case LEFT:
		bullet->bullet_x -= 3;
		x2 = x1;
		y2 = y1 - 1;
		break;
	case RIGHT:
		bullet->bullet_x += 3;
		x2 = x1;
		y2 = y1 - 1;
		break;
	}

	if (bullet->bullet_x < 0 || bullet->bullet_x>650 || bullet->bullet_y < 0 || bullet->bullet_y>650)
	{
		bullet->state = 0;
		return;
	}
	//***************  �ӵ�����������ǽ������ǽ��ͬʱ���ӵ���״̬��Ϊ 0  
	if (map[y1][x1] == 1 && map[y2][x2] == 1)
	{
		setfillcolor(BLACK);
		solidrectangle(x1 * 25, y1 * 25, x1 * 25 + 25, y1 * 25 + 25); //  ����ͼ���±��
		solidrectangle(x2 * 25, y2 * 25, x2 * 25 + 25, y2 * 25 + 25);
		map[y1][x1] = 0;
		map[y2][x2] = 0;
		bullet->state = 0;
		return;
	}
	else if (map[y1][x1] == 1 && map[y2][x2] == 0)
	{
		setfillcolor(BLACK);
		solidrectangle(x1 * 25, y1 * 25, x1 * 25 + 25, y1 * 25 + 25);
		map[y1][x1] = 0;
		bullet->state = 0;
		return;
	}
	else if (map[y1][x1] == 0 && map[y2][x2] == 1)
	{
		setfillcolor(BLACK);
		solidrectangle(x2 * 25, y2 * 25, x2 * 25 + 25, y2 * 25 + 25);
		map[y2][x2] = 0;
		bullet->state = 0;
		return;
	}
	else if (map[y1][x1] == 2 && map[y2][x2] == 2)   //�ӵ�������������ǽ�����»��ư�ǽͼƬ������ǽ�ϻ��е��ӣ��������ӵ�״̬Ϊ0
	{
		putimage(x1 * 25, y1 * 25, &Wall2);
		putimage(x2 * 25, y2 * 25, &Wall2);
		bullet->state = 0;
		return;
	}
	else if (map[y1][x1] == 2 && map[y2][x2] != 2)
	{
		putimage(x1 * 25, y1 * 25, &Wall2);
		bullet->state = 0;
		return;
	}
	else if (map[y1][x1] != 2 && map[y2][x2] == 2)
	{
		putimage(x2 * 25, y2 * 25, &Wall2);
		bullet->state = 0;
		return;
	}
	if (map[y1][x1] == 4 && map[y2][x2] == 4)
	{
		flag = 0;
	}
	if (tell)                 //���tell ��Ϊ0   Ϊ�ҷ�̹���ӵ���ײ���
	{
		if ((map[y1][x1] >= 100 && map[y1][x1] <= 109) || (map[y2][x2] >= 100 && map[y2][x2] <= 109))
		{
			PlaySound(_T("hit.wav"), NULL, SND_FILENAME | SND_ASYNC);
			setfillcolor(BLACK);
			TANK* Tank = NULL;
			bullet->state = 0;
			if (map[y1][x1] >= 100 && map[y1][x1] <= 109)
			{
				Tank = map[y1][x1] - 100 + tank;
			}
			else if (map[y2][x2] >= 100 && map[y2][x2] <= 109)
			{
				Tank = map[y2][x2] - 100 + tank;
			}
			Tank->state = 0;
			map_par(Tank, 0);
			enemyAlive--;
			putTankBoom(Tank->tank_x, Tank->tank_y);
			solidrectangle(Tank->tank_x * 25, Tank->tank_y * 25, Tank->tank_x * 25 + 50, Tank->tank_y * 25 + 50);
		}
	}
	else                         //���tellΪ0  Ϊ�з�̹�˼��
	{
		if ((map[y1][x1] == 200 && map[y1][x1] == 200) || (map[y2][x2] == 200 && map[y2][x2] == 200))
		{
			bullet->state = 0;
			map_par(tank, 0);
			enemyAlive--;
			tank->state = 0;
			putTankBoom(tank->tank_x, tank->tank_y);
			flag = 0;
			return;
		}
		else if ((map[y1][x1] >= 100 && map[y1][x1] <= 109) || (map[y2][x2] >= 100 && map[y2][x2] <= 109))
		{
			bullet->state = 0;
		}
	}
	if (bullet->state == 1)
	{
		setfillcolor(WHITE);
		solidcircle(bullet->bullet_x, bullet->bullet_y, 2);
	}
}

// ******************************* ̹���ƶ����� *****************************
void allTankMove(TANK* tank, DIRECTION direction, IMAGE* img, int n)
{
	switch (direction)
	{                                   //̹����ǰ
	case UP:
		if (tank->direction == UP && (tank->tank_y - 1) >= 0 && map[tank->tank_y - 1][tank->tank_x] == 0 && map[tank->tank_y - 1][tank->tank_x + 1] == 0)
		{
			tankMove(tank, UP, img, n);
		}
		else if (tank->direction != UP)
		{
			tank->direction = UP;
			putimage(tank->tank_x * 25, tank->tank_y * 25, img);
		}
		break;                                       //̹�����
	case DOWN:
		if (tank->direction == DOWN && (tank->tank_y + 2) <= 25 && map[tank->tank_y + 2][tank->tank_x] == 0 && map[tank->tank_y + 2][tank->tank_x + 1] == 0)
		{
			tankMove(tank, DOWN, img, n);
		}
		else if (tank->direction != DOWN)
		{
			tank->direction = DOWN;
			putimage(tank->tank_x * 25, tank->tank_y * 25, img);
		}
		break;                                           //̹������
	case LEFT:
		if (tank->direction == LEFT && (tank->tank_x - 1) >= 0 && map[tank->tank_y][tank->tank_x - 1] == 0 && map[tank->tank_y + 1][tank->tank_x - 1] == 0)
		{
			tankMove(tank, LEFT, img, n);
		}
		else if (tank->direction != LEFT)
		{
			tank->direction = LEFT;
			putimage(tank->tank_x * 25, tank->tank_y * 25, img);
		}
		break;                                               //̹������
	case RIGHT:
		if (tank->direction == RIGHT && (tank->tank_x + 2) <= 25 && map[tank->tank_y][tank->tank_x + 2] == 0 && map[tank->tank_y + 1][tank->tank_x + 2] == 0)
		{
			tankMove(tank, RIGHT, img, n);
		}
		else if (tank->direction != RIGHT)
		{
			tank->direction = RIGHT;
			putimage(tank->tank_x * 25, tank->tank_y * 25, img);
		}
		break;
	}
}
//*********************   ��Ϸ��ʼ�����ҷ�̹��  ********************
void gameStart()
{
	srand((unsigned)time(NULL));
	int times = 0;                            //��¼��ǰ��������ߴ���
	int enemyTotal = 0;
	int enemyAlive = 10;
	//PlaySound(TEXT("background.wav"), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	//***********************  �ҷ�̹�� ********************
	TANK myTankMove;                              //����̹��
	BULLET myBulletMove;                           //�����ӵ�
	IMAGE myTank_img[4];
	loadimage(&myTank_img[UP], _T("tank_up.jpg"), 50, 50);
	loadimage(&myTank_img[DOWN], _T("tank_down.jpg"), 50, 50);
	loadimage(&myTank_img[LEFT], _T("tank_left.jpg"), 50, 50);
	loadimage(&myTank_img[RIGHT], _T("tank_right.jpg"), 50, 50);
	myTankMove.tank_x = 8;                           //��ʼ������̹��λ��
	myTankMove.tank_y = 24;
	myTankMove.direction = UP;
	myTankMove.state = true;
	map_par(&myTankMove, 200);
	putimage(myTankMove.tank_x * 25, myTankMove.tank_y * 25, &myTank_img[myTankMove.direction]);                           //��ʼ������̹�˷���
	myBulletMove.direction = DIRECTION(myTankMove.direction);
	myBulletMove.state = 0;
	//***************************  �з�̹�� *********************
	TANK enemyTank[ENENMY_TANK_NUMBER];  // Tank �ṹ����
	BULLET enemyBUllet[ENENMY_TANK_NUMBER];
	IMAGE enemyTank_img[4]; // IMGRE����
	loadimage(&enemyTank_img[UP], _T("enemy_tank_up.gif"), 50, 50);
	loadimage(&enemyTank_img[DOWN], _T("enemy_tank_down.gif"), 50, 50);
	loadimage(&enemyTank_img[LEFT], _T("enemy_tank_left.gif"), 50, 50);
	loadimage(&enemyTank_img[RIGHT], _T("enemy_tank_right.gif"), 50, 50);
	for (int i = 0; i < ENENMY_TANK_NUMBER; i++)
	{
		enemyTank[i].tank_y = 0;
		if (i % 3 == 0)
		{
			enemyTank[i].tank_x = 0;
		}
		else if (i % 3 == 1)
		{
			enemyTank[i].tank_x = 12;
		}
		else if (i % 3 == 2)
		{
			enemyTank[i].tank_x = 24; 
		}
		enemyTank[i].state = true;
		enemyTank[i].direction = DOWN;
		enemyBUllet[i].direction = DIRECTION(enemyTank[i].direction);
		enemyBUllet[i].state = 0;
	}
	for (int i = 0; i < 3; i++)
	{
		map_par(&enemyTank[i], 100 + i);
		putimage(enemyTank[i].tank_x * 25, enemyTank[i].tank_y * 25, &enemyTank_img[DOWN]);
	}
	enemyTotal = 3;
	// ***************   �������¼�  *******************
	bool Flag = 1;
	while (1)
	{
		//����̹�˳���
		if (times % 400 == 0 && times != 0 && enemyTotal <= ENENMY_TANK_NUMBER)
		{
			//increase++;
			map_par(&enemyTank[enemyTotal], 100 + enemyTotal);
			putimage(enemyTank[enemyTotal].tank_x * 25, enemyTank[enemyTotal].tank_y * 25, &enemyTank_img[DOWN]);
			enemyTotal++;
		}
		// ���Ƶط�̹�˸ı䷽�� 
		if (times % 200 == 0)
		{
			for (int i = 0; i < enemyTotal; i++)
			{
				if (enemyTank[i].state)
				{
					DIRECTION NowDirection;
					if (i % 2 == 0)        //˫��̹�˹����ҷ��ϳ�
					{
						NowDirection = enemyMove(&enemyTank[i], 12, 24);
						allTankMove(&enemyTank[i], NowDirection, &enemyTank_img[NowDirection], 100 + i);
					}
					else                    //����̹�˹����ҷ�̹��
					{
						NowDirection = enemyMove(&enemyTank[i], myTankMove.tank_x, myTankMove.tank_y);
						allTankMove(&enemyTank[i], NowDirection, &enemyTank_img[NowDirection], 100 + i);
					}
					tankFire(&enemyTank[i], &enemyBUllet[i], false);
				}
			}
		}
		else if (times % 50 == 0)   //���Ƶз�̹���ƶ�
		{
			for (int i = 0; i < enemyTotal; i++)
			{
				if (enemyTank[i].state)
				{
					allTankMove(&enemyTank[i], DIRECTION(enemyTank[i].direction), &enemyTank_img[enemyTank[i].direction], 100 + i);
				}
			}

		}
		// *********************************   �ҷ�̹���ƶ���������� ****************************
		if (_kbhit())
		{
			char key = _getch();                           //��ȡ��������ֵ
			switch (key)
			{
			case 'w':                                   //̹����ǰ
			case 'W':
				allTankMove(&myTankMove, UP, &myTank_img[UP], 200);
				break;
			case 's':                                        //̹�����
			case 'S':
				allTankMove(&myTankMove, DOWN, &myTank_img[DOWN], 200);
				break;
			case 'a':                                           //̹������
			case 'A':
				allTankMove(&myTankMove, LEFT, &myTank_img[LEFT], 200);
				break;
			case 'd':                                               //̹������
			case 'D':
				allTankMove(&myTankMove, RIGHT, &myTank_img[RIGHT], 200);
				break;
			case 'p':                                                   //��ͣ��Ϸ�����������ʼ
			case 'P':
				system("pause");
				break;
			case 'j':                                                //���
			case 'J':
				tankFire(&myTankMove, &myBulletMove, true);
				break;
			}
		}
		for (int i = 0; i < enemyTotal; i++)
		{
			if (enemyBUllet[i].state == 1)            //�ӵ�����ʱ�����µз��ӵ�����λ��
			{
				bulletMove(&enemyBUllet[i], flag, 0, &myTankMove, enemyAlive);
				if (!flag)
				{
					Flag = 0;
				}
			}
		}
		if (!Flag)
			break;
		if (myBulletMove.state == 1)            //�ӵ�����ʱ�������ҷ��ӵ�����λ��
		{
			bulletMove(&myBulletMove, flag, 1, enemyTank, enemyAlive);
			if (!flag)
			{
				break;

			}
		}
		if (enemyAlive == 0)
			break;
		times++;
		Sleep(15);
	}
}
int main()
{
	initgraph(650, 650);                  //��ʼ������
	outputPage1();
	outputPage2();
	gameStart();
	if (!flag)
	{
		putGameOver();
	}
	else
	{
		victory();
	}
	system("pause");
	closegraph();
	return 0;
}

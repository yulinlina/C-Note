#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<conio.h>
#include<time.h>
int position_x, position_y;
int high, width;
int bullet_x, bullet_y;
int enemy_x, enemy_y;
int speed;
int score; // �÷�
void HideCursor() // �������ع��
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };  // �ڶ���ֵΪ0��ʾ���ع��
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}
void startup() {
	high = 40;
	width = 60;
	position_x = width / 2;
	position_x = high / 2;
	bullet_x = position_x;
	bullet_y = -2;
	enemy_x = 0;
	enemy_y = 0;
	speed = 0;
	srand(time(0));
	score = 0;
	HideCursor();
}
void gotoxy(int x, int y)  //����ƶ���(x,y)λ��
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}
void show() {
	int i, j;
	system("cls");
	gotoxy(0, 0);
	for (i = 0; i < high; i++)
	{
		for (j = 0; j < width; j++) {
			if ((i == position_y) && (j == position_x))
				printf("*");
			else if ((i == bullet_y) && (j == bullet_x))
				printf("|");
			else if ((i == enemy_y) && (j == enemy_x))
				printf("@");
			else
				printf(" ");
		}
		printf("\n");
	}
	printf("score:%d\n", score);
}
void update_without_input() {
	if (bullet_y > -1)
		bullet_y--;
	if ((bullet_x == enemy_x) && (bullet_x == enemy_y)) {
		score++;
		enemy_y = -1;
		enemy_x = rand() % width;
		bullet_y = -2;
	}
	if (enemy_y > high) {
		enemy_y = -1;
		enemy_x =rand()%width;
	}
	int max_speed = 5;
	if (speed < max_speed)speed++;
	if (speed >= max_speed) {
		enemy_y++;
		speed = 0;
	}
}
void update_with_input()
{
	char input;
	int is_fire = 0;
	if (_kbhit()) {
		/* move*/
		//scanf("%c", &input);
		input = _getch(); // ������س�Ҳ����ʾ
		if (input == 'a') position_x--;
		if (input == 'd') position_x++;
		if (input == 'w') position_y--;
		if (input == 's') position_y++;
		if (input == ' ') {
			bullet_x = position_x;
			bullet_y = position_y - 1;
		}
	}
}
int main()
{
	startup();
	while (1) {
		show();
		update_without_input();
		update_with_input();
	}
	return 0;
}



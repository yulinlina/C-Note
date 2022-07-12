#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<conio.h>
int main()
{
	int i, j;
	int x = 5, v = 1;
	int y = 10;
	/*
	* x axis speed
	*/
	int top = 0, left = 0;
	int right = 30, bottom = 30;
	int vx = 1, vy = 1;
	char input;
	int is_fire = 0;
	while (1) {
		system("cls");  // clear the screen
		//y = y + vy;    // change the height
		//if (y == top || y == bottom) {
		//	vy= -vy;
		/*x = x + vx;
		if (x == left || x == right) vx = -vx;*/
		for (i = 0; i < y; i++) printf("\n");  // 
		for (j = 0; j < x; j++) printf(" ");
		//printf("o\n");
		// 输出复杂的飞机
		for (j = 0; j < x; j++) printf("");
		printf(" *\n");
		for (j = 0; j < x; j++) printf(" ");
		printf("******\n");
		for (j = 0; j < x; j++)printf(" ");
		printf("**\n");
		if (_kbhit()) {
			/* move*/
			//scanf("%c", &input);
			input = _getch(); // 不输入回车也不显示
			if (input == 'a') x--;
			if (input == 'd') x++;
			if (input == 'w') y--;
			if (input == 's') y++;
			if (input == ' ') is_fire = 1;
			/*	system("cls");
				if (is_fire == 0) {
					for (i = 0; i < y; i++)printf("\n");
				}
				else {
					for (j = 0; j < y; j++) {
						for (i = 0; i < x; i++)printf(" ");
						printf(" |\n");
					}
				}*/
		}
		Sleep(50);
	}
	return 0;
}
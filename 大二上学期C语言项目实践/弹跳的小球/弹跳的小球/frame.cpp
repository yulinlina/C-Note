#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<conio.h>
int position_x,position_y;
int high, width;
void startup() {
	high = 20;
	width = 30;
	position_x = width / 2;
	position_x = high / 2;
}
void show() {
	int i, j;
	system("cls");
	for (i = 0; i < high; i++)
	{
		for (j = 0; j < width; j++) {
			if ((i == position_y) && (j == position_x))
				printf("*");
			else
				printf(" ");
		}
		printf("\n");
	}
}
void update_without_input(){
}
void update_with_input()
{
	char input;
	int is_fire = 0;
	if (_kbhit()) {
		/* move*/
		//scanf("%c", &input);
		input = _getch(); // 不输入回车也不显示
		if (input == 'a') position_x--;
		if (input == 'd') position_x++;
		if (input == 'w') position_y--;
		if (input == 's') position_y--;
		if (input == ' ') is_fire = 1;
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



#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>

// ÒýÓÃ Windows Multimedia API
#pragma comment(lib,"Winmm.lib")

#define	 W	350
#define  H  600

#define BIRD_H	24
#define BAR_W	140
#define BAR_H	600

IMAGE img_bk, img_bd1, img_bd2, img_bar_up1, img_bar_up2, img_bar_down1, img_bar_down2;
int bird_x, bird_y;
int bar1_x, bar1_yDown, bar1_yTop;
int score;

void gameover();

void startup()
{
	initgraph(W, H);
	loadimage(&img_bk, "..\\data\\background.jpg");
	loadimage(&img_bd1, "..\\data\\bird1.jpg");
	loadimage(&img_bd2, "..\\data\\bird2.jpg");
	loadimage(&img_bar_up1, "..\\data\\bar_up1.gif");
	loadimage(&img_bar_up2, "..\\data\\bar_up2.gif");
	loadimage(&img_bar_down1, "..\\data\\bar_down1.gif");
	loadimage(&img_bar_down2, "..\\data\\bar_down2.gif");
	bird_x = 100;
	bird_y = H / 2;

	bar1_x = W-100;
	bar1_yDown = (int)(H * 0.3);
	bar1_yTop = (int)(H * 0.5);
	srand((unsigned int)time(0));
	score = 0;

	BeginBatchDraw();

	mciSendString("open ..\\data\\background.mp3 alias bkmusic", NULL, 0, NULL);
	mciSendString("play bkmusic repeat", NULL, 0, NULL);  
}

void show()
{
	putimage(0, 0, &img_bk);	
	putimage(bar1_x, bar1_yDown-BAR_H, &img_bar_up1, NOTSRCERASE);
	putimage(bar1_x, bar1_yDown-BAR_H, &img_bar_up2, SRCINVERT);
	putimage(bar1_x, bar1_yTop, &img_bar_down1, NOTSRCERASE);
	putimage(bar1_x, bar1_yTop, &img_bar_down2, SRCINVERT);
	putimage(bird_x, bird_y, &img_bd1, NOTSRCERASE); 
	putimage(bird_x, bird_y, &img_bd2, SRCINVERT);

	char strout[64];

	sprintf_s(strout, "得分：%d", score);
	setcolor(RED);
	settextstyle(24, 0, _T("Courier"));
	outtextxy(W-100, 10, _T(strout));

	FlushBatchDraw();
	Sleep(50);
}

void updateWithoutInput()
{
	bird_y = bird_y + 2;
	if (bird_y >= H - BIRD_H) bird_y = H - BIRD_H;
		
	if (bird_x >= bar1_x && bird_x <= bar1_x+ BAR_W)
	{
		if ((bird_y >= bar1_yDown) && (bird_y <= bar1_yTop - BIRD_H))
		{
			if (bird_x == bar1_x + BAR_W)	score++;
		}
		else
		{
			setcolor(RED);
			settextstyle(48, 0, _T("Courier"));
			outtextxy(50, 250, _T("Game Over"));
			FlushBatchDraw();

			gameover();				
			exit(0);			
		}
	}

	bar1_x--;        
	if (bar1_x <= -BAR_W)
	{
		bar1_x = W-100;
		int temp = rand() % (int)(H*0.7);
		bar1_yDown = temp;
		bar1_yTop = temp + (int)(H*0.2);
	}
}

void updateWithInput()
{
	char input;
	if (_kbhit())    
	{
		input = _getch();
		if (input == ' ' && bird_y > 20)
		{
			bird_y = bird_y - 30;
			mciSendString("close jpmusic", NULL, 0, NULL); 
			mciSendString("open ..\\data\\Jump.mp3 alias jpmusic", NULL, 0, NULL);
			mciSendString("play jpmusic", NULL, 0, NULL); 
		}
	}
}

void gameover()
{
	EndBatchDraw();
	_getch();
	closegraph();
}

int main()
{
	startup();  

	while (1)  
	{
		show();  
		updateWithoutInput();  
		updateWithInput();     
	}
	gameover();     
	return 0;
}

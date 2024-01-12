#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "game.h"
#include <time.h>

void menu()
{
	printf("*************************\n");
	printf("******输入1开始游戏******\n");
	printf("******输入0退出游戏******\n");
	printf("*************************\n");
	printf("王子公主请选择：>");

}

void game()
{
	
	while (1)
	{
		char board[ROW][COL] = { 0 };
		//初始化棋盘的二维数组
		scanfboard(board, ROW, COL);
		//初始化棋盘
		printf("请在以下棋盘中输入坐标\n");
		displayboard(board, ROW, COL);
		//打印棋盘展示给玩家看的函数
		char ret = 0;
		int ret2 = 0;
		int i = 1;
		while (1)
		{
			printf("%s%d%s\n", "第", i, "回合");
			playermove(board, ROW, COL);
			displayboard(board, ROW, COL);
			ret2 = isfull(board, ROW, COL);
			if (ret2 == 1)
			{
				printf("平局\n"); break;
			}
			ret = iswin(board, ROW, COL);
			if (ret != 'c')
			{
				if (ret == '*')
				{
					printf("******\n******\n******\n玩家赢了\n******\n******\n******\n"); 
					break;
					
				}
			}
			computermove(board, ROW, COL);
			displayboard(board, ROW, COL);
			ret2 = isfull(board, ROW, COL);
			if (ret2 == 1)
			{
				printf("平局\n"); break;
			}
			ret = iswin(board, ROW, COL);
			if (ret != 'c')
			{
				if (ret == '#')
				{
					printf("******\n******\n******\n电脑赢了\n******\n******\n******\n"); 
					break;
				}
			}
			i++;
		}
	}
}

int main()
{
	printf("@→y\n");
	printf("↓\n");
	printf("x\n");
	srand((unsigned)time(NULL));//为随机数生成器设定当前时间的种子，以便我们每次生成的数字都会有所不同
	menu();
	int input = 0;
	do
	{
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("开始游戏\n");
			game();//游戏实现代码的函数
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("请选择0或者1\n");
			break;
		}
	} while (input);
	return 0;
}
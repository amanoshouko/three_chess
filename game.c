#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "game.h"
#include <stdlib.h>
void scanfboard(char board[ROW][COL], int row, int col)//初始化玩家输入的二维数组
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void displayboard(char board[ROW][COL], int row, int col)//将存储在内存中的数据打印出来展示给玩家看
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}

		}
		 printf("\n");
		 if (i < row - 1)//打印分割线
		 {
			 for (j = 0; j < col; j++)
			 {
				 printf("---");
				 if (j < col-1)
					 printf("|");
			 }
		 }
		 printf("\n");
	}
}

void playermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("轮到玩家下棋\n");
	printf("请输入坐标:>");
	while (1)
	{
		scanf("%d %d", &x, &y);
		if (x < row + 1 && y < col + 1&&x>=1&&y>=1)//坐标未超过范围的情况下
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("格子已被占用\n");
				printf("请重新输入:>");
			}
		}
		else
		{
			printf("非法坐标，请重新输入\n");
			printf("请重新输入:>");
		}
	}
}

void computermove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("电脑已下棋\n");
	while (1)
	{
		x = rand()%row; y = rand()%col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

char iswin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//玩家行
	if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
	{
		return board[i][1];
	}
	//玩家列
	if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
	{
		return board[1][j];
	}
	//玩家对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	else
	{
		return 'c';
	}
}

int isfull(char board[ROW][COL], int row, int col)
{
	int a=1;
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		if (a == 0)break;
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
			   a=0; break;
			}
		}
	}
   return a;	
}
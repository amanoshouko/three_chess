#pragma once
#define ROW 3
#define COL 3
void scanfboard(char board[ROW][COL], int row, int col);//初始化棋盘

void displayboard(char board[ROW][COL], int row, int col);//展示棋盘

void playermove(char board[ROW][COL], int row, int col);//玩家下棋

void computermove(char board[ROW][COL], int row, int col);//电脑下棋

char iswin(char board[ROW][COL], int row, int col);//判断谁赢函数

int isfull(char board[ROW][COL], int row, int col);
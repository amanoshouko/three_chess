#pragma once
#define ROW 3
#define COL 3
void scanfboard(char board[ROW][COL], int row, int col);//��ʼ������

void displayboard(char board[ROW][COL], int row, int col);//չʾ����

void playermove(char board[ROW][COL], int row, int col);//�������

void computermove(char board[ROW][COL], int row, int col);//��������

char iswin(char board[ROW][COL], int row, int col);//�ж�˭Ӯ����

int isfull(char board[ROW][COL], int row, int col);
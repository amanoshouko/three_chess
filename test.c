#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "game.h"
#include <time.h>

void menu()
{
	printf("*************************\n");
	printf("******����1��ʼ��Ϸ******\n");
	printf("******����0�˳���Ϸ******\n");
	printf("*************************\n");
	printf("���ӹ�����ѡ��>");

}

void game()
{
	
	while (1)
	{
		char board[ROW][COL] = { 0 };
		//��ʼ�����̵Ķ�ά����
		scanfboard(board, ROW, COL);
		//��ʼ������
		printf("����������������������\n");
		displayboard(board, ROW, COL);
		//��ӡ����չʾ����ҿ��ĺ���
		char ret = 0;
		int ret2 = 0;
		int i = 1;
		while (1)
		{
			printf("%s%d%s\n", "��", i, "�غ�");
			playermove(board, ROW, COL);
			displayboard(board, ROW, COL);
			ret2 = isfull(board, ROW, COL);
			if (ret2 == 1)
			{
				printf("ƽ��\n"); break;
			}
			ret = iswin(board, ROW, COL);
			if (ret != 'c')
			{
				if (ret == '*')
				{
					printf("******\n******\n******\n���Ӯ��\n******\n******\n******\n"); 
					break;
					
				}
			}
			computermove(board, ROW, COL);
			displayboard(board, ROW, COL);
			ret2 = isfull(board, ROW, COL);
			if (ret2 == 1)
			{
				printf("ƽ��\n"); break;
			}
			ret = iswin(board, ROW, COL);
			if (ret != 'c')
			{
				if (ret == '#')
				{
					printf("******\n******\n******\n����Ӯ��\n******\n******\n******\n"); 
					break;
				}
			}
			i++;
		}
	}
}

int main()
{
	printf("@��y\n");
	printf("��\n");
	printf("x\n");
	srand((unsigned)time(NULL));//Ϊ������������趨��ǰʱ������ӣ��Ա�����ÿ�����ɵ����ֶ���������ͬ
	menu();
	int input = 0;
	do
	{
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��ʼ��Ϸ\n");
			game();//��Ϸʵ�ִ���ĺ���
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("��ѡ��0����1\n");
			break;
		}
	} while (input);
	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include"game.h"
void menu()
{
	printf("************************************************\n");
	printf("************     1. play       *****************\n");
	printf("************     0. exit       *****************\n");
	printf("************************************************\n");
}

void game()
{
	// 存储数据-二维数组
	char board[ROW][COL];
	// 初始化棋盘 - 置入空格
	InitBoard(board,ROW,COL);

	//打印棋盘
	DisplayBoard(board,ROW,COL);

	char ret = 0;
	while (1)
	{
		//玩家下棋
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}

		//电脑下棋
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家胜利\n");
	}
	else if (ret == '#')
	{
		printf("电脑胜利\n");
	}
	else
	{
		printf("平局\n");
	}
}

int main()
{
	int input = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("没有该选项，请重新选择\n");
			break;
		}

	} while (0 != input);
	return 0;
}
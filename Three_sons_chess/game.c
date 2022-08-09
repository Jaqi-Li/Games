#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

void InitBoard(char(*board)[COL], int row, int col)
{
	int i;
	int j;
	for (i = 0; i < row; ++i)
	{
		for (j = 0; j < col; ++j)
		{
			//*(*(board + i) + j) = ' ';
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char(*board)[COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; ++i)
	{
		for (j = 0; j < col; ++j)
		{
			printf("%3c", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; ++j)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
			printf("\n");
		}
	}
}

void PlayerMove(char(*board)[COL], int row, int col)
{
	int moveX, moveY;

	printf("玩家下棋>\n");

	while (1)
	{
		printf("请输入下棋的坐标:>");
		scanf("%d %d", &moveX, &moveY);

		//判断坐标合法性
		if (moveX >= 1 && moveX <= ROW && moveY >= 1 && moveY <= COL)
		{
			// 下棋
			// 判断是否占用
			if (board[moveX - 1][moveY - 1] == ' ')
			{
				board[moveX - 1][moveY - 1] = '*';
				break;
			}
			else
			{
				printf("该位置已有棋子，请重新选择输入\n");
			}
		}
		else
		{
			printf("错误的坐标，请重新选择输入\n");
		}
	}
}

void ComputerMove(char(*board)[COL], int row, int col)
{
	printf("电脑下棋>\n");

	while (1)
	{
		int moveX = rand() % row;
		int moveY = rand() % col;
		
		// 下棋
		// 判断是否占用
		if (board[moveX][moveY] == ' ')
		{
			board[moveX][moveY] = '#';
			break;
		}
	}
}

char IsWin(char(*board)[COL], int row, int col)
{
	int i, j;
	// 判断行
	for (i = 0; i < row; ++i)
	{
		for (j = 0; j < col - 2; ++j)
		{
			if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i][j + 2] && board[i][j] != ' ')
			{
				return board[i][j];
			}
		}
	}

	// 判断列
	for (j = 0; j < col; ++j)
	{
		for (i = 0; i < row - 2; ++i)
		{
			if (board[i][j] == board[i + 1][j] && board[i + 1][j] == board[i + 2][j] && board[i][j] != ' ')
			{
				return board[i][j];
			}
		}
	}

	// 判断对角线
	for (i = 0; i < row - 2; ++i)
	{
		for (j = 0; j < col - 2; ++j)
		{
			if (board[i][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i + 2][j + 2] && board[i][j] != ' ')
			{
				return board[i][j];
			}
		}
	}

	// 判断反对角线
	for (i = 0; i < row - 2; ++i)
	{
		for (j = col - 1; j > 1; --j)
		{
			if (board[i][j] == board[i + 1][j - 1] && board[i + 1][j - 1] == board[i + 2][j - 2] && board[i][j] != ' ')
			{
				return board[i][j];
			}
		}
	}

	// 判断平局
	if (IsFull(board,row,col))
	{
		return 'Q';
	}
	return 'C';
}

int IsFull(char(*board)[COL], int row, int col)
{
	int i, j;
	for (i = 0; i < row; ++i)
	{
		for (j = 0; j < col; ++j)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}
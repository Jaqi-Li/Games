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

	printf("�������>\n");

	while (1)
	{
		printf("���������������:>");
		scanf("%d %d", &moveX, &moveY);

		//�ж�����Ϸ���
		if (moveX >= 1 && moveX <= ROW && moveY >= 1 && moveY <= COL)
		{
			// ����
			// �ж��Ƿ�ռ��
			if (board[moveX - 1][moveY - 1] == ' ')
			{
				board[moveX - 1][moveY - 1] = '*';
				break;
			}
			else
			{
				printf("��λ���������ӣ�������ѡ������\n");
			}
		}
		else
		{
			printf("��������꣬������ѡ������\n");
		}
	}
}

void ComputerMove(char(*board)[COL], int row, int col)
{
	printf("��������>\n");

	while (1)
	{
		int moveX = rand() % row;
		int moveY = rand() % col;
		
		// ����
		// �ж��Ƿ�ռ��
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
	// �ж���
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

	// �ж���
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

	// �ж϶Խ���
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

	// �жϷ��Խ���
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

	// �ж�ƽ��
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
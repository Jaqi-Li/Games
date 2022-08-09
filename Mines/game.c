#include"game.h"

void InitArea(char(*area)[COLS], int rows, int cols, char element)
{
	int i, j;
	for (i = 0; i < rows; ++i)
	{
		for (j = 0; j < cols; ++j)
		{
			area[i][j] = element;
		}
	}
}

void PrintArea(char(*show)[COLS], int row, int col)
{
	int i, j;
	printf("======================ɨ����Ϸ==============================\n");
	for (j = 0; j <= col; ++j)
	{
		printf("%d ", j);
	}
	printf("\n");
	for (i = 1; i <= row; ++i)
	{
		printf("%d ", i);
		for (j = 1; j <= col; ++j)
		{
			printf("%c ", show[i][j]);
		}
		printf("\n");
	}
	printf("======================ɨ����Ϸ==============================\n");

}

void SetMine(char(*mine)[COLS], int row, int col)
{
	int count = MINECOUNTS;
	int x, y;

	while (count)
	{
		
		x = rand() % row + 1;
		y = rand() % col + 1;

		if ('0' == mine[x][y])
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

void SetShow(char(*mine)[COLS], char(*show)[COLS], int x, int y)
{
	int i, j, num;
	num = 0;
	for (i = x - 1; i <= x + 1; ++i)
	{
		for (j = y - 1; j <= y + 1; ++j)
		{
			if ('1' == mine[i][j])
			{
				num++;
			}
		}
	}
	show[x][y] = num + '0';
}

void FindMine(char(*mine)[COLS], char(*show)[COLS], int row, int col)
{
	// 1. ��������
	// 2. ������ף���Ϸ����
	//	  ������ʾ��Χ�ж��ٸ��ף���Ϸ����
	int x, y,win = 0;
	while (win < row * col -MINECOUNTS)
	{
		printf("��������Ҫ���׵�����(eg:1 1)��");
		scanf("%d %d", &x, &y);
		if (x<1 || x>row || y<1 || y>col)
		{
			printf("����Խ�磬����������");
		}
		if ('*' != show[x][y])
		{
			printf("�������Ѿ��Ų飬����������");
		}
		else
		{
			if ('1' == mine[x][y])
			{
				printf("Game Over!\n");
				PrintArea(mine, row, col);
				break;
			}
			else
			{
				SetShow(mine,show, x, y);
				PrintArea(show, row, col);
				win++;
			}
		}
	}
	if (win == row * col - MINECOUNTS)
	{
		printf("ʤ����");
		PrintArea(mine, row, col);
	}
}



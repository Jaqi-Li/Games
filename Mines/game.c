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
	printf("======================扫雷游戏==============================\n");
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
	printf("======================扫雷游戏==============================\n");

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
	// 1. 输入坐标
	// 2. 如果踩雷，游戏结束
	//	  否则显示周围有多少个雷，游戏继续
	int x, y,win = 0;
	while (win < row * col -MINECOUNTS)
	{
		printf("请输入您要排雷的坐标(eg:1 1)：");
		scanf("%d %d", &x, &y);
		if (x<1 || x>row || y<1 || y>col)
		{
			printf("坐标越界，请重新输入");
		}
		if ('*' != show[x][y])
		{
			printf("该坐标已经排查，请重新输入");
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
		printf("胜利！");
		PrintArea(mine, row, col);
	}
}



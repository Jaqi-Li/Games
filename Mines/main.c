#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

/*********************************************************************************/
/*								使用两个数组实现扫雷	                         */
/*********************************************************************************/

void menu()
{
	printf("************************************************\n");
	printf("************    扫雷游戏       *****************\n");
	printf("************     1. play       *****************\n");
	printf("************     0. exit       *****************\n");
	printf("************************************************\n");
}

void game()
{
	//	存储雷区  存储信息
	char mine[ROWS][COLS];
	char show[ROWS][COLS];

	//	初始化
	InitArea(mine, ROWS, COLS,'0');
	InitArea(show, ROWS, COLS,'*');

	// 埋雷
	SetMine(mine, ROW, COL);
	printf("已经埋好雷了，开始排雷吧！\n");
	PrintArea(show, ROW, COL);

	//排雷
	FindMine(mine, show, ROW, COL);
}

int main()
{
	int input;
	srand((unsigned int)time(NULL));
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
	} while (input);

	return 0;
}
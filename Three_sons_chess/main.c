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
	// �洢����-��ά����
	char board[ROW][COL];
	// ��ʼ������ - ����ո�
	InitBoard(board,ROW,COL);

	//��ӡ����
	DisplayBoard(board,ROW,COL);

	char ret = 0;
	while (1)
	{
		//�������
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = IsWin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}

		//��������
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
		printf("���ʤ��\n");
	}
	else if (ret == '#')
	{
		printf("����ʤ��\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}

int main()
{
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("û�и�ѡ�������ѡ��\n");
			break;
		}

	} while (0 != input);
	return 0;
}
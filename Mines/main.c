#define _CRT_SECURE_NO_WARNINGS
#include"game.h"

/*********************************************************************************/
/*								ʹ����������ʵ��ɨ��	                         */
/*********************************************************************************/

void menu()
{
	printf("************************************************\n");
	printf("************    ɨ����Ϸ       *****************\n");
	printf("************     1. play       *****************\n");
	printf("************     0. exit       *****************\n");
	printf("************************************************\n");
}

void game()
{
	//	�洢����  �洢��Ϣ
	char mine[ROWS][COLS];
	char show[ROWS][COLS];

	//	��ʼ��
	InitArea(mine, ROWS, COLS,'0');
	InitArea(show, ROWS, COLS,'*');

	// ����
	SetMine(mine, ROW, COL);
	printf("�Ѿ�������ˣ���ʼ���װɣ�\n");
	PrintArea(show, ROW, COL);

	//����
	FindMine(mine, show, ROW, COL);
}

int main()
{
	int input;
	srand((unsigned int)time(NULL));
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
	} while (input);

	return 0;
}
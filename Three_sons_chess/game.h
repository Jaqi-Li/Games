#pragma once
#include<stdio.h>
/*********************************************************************************/
/*								��������										*/
/*********************************************************************************/

#define ROW 5
#define COL 5

/*********************************************************************************/
/*								��������									 	 */
/*********************************************************************************/

// ��ʼ������
void InitBoard(char (*board)[COL], int row, int col);

// ��ӡ����
void DisplayBoard(char(*board)[COL], int row, int col);

// �������
void PlayerMove(char(*board)[COL], int row, int col);

// ��������
void ComputerMove(char(*board)[COL], int row, int col);

// �ж��Ƿ���һ��Ӯ��
char IsWin(char(*board)[COL], int row, int col);

// �ж������Ƿ��� 0--δ����1--��
int IsFull(char(*board)[COL], int row, int col);
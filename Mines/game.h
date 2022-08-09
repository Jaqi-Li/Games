#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<stdlib.h>

/*********************************************************************************/
/*								��������										*/
/*********************************************************************************/
#define ROW (9)
#define COL (9)

#define ROWS (ROW + 2)
#define COLS (COL + 2)

#define MINECOUNTS (10)


/*********************************************************************************/
/*								��������									 	 */
/*********************************************************************************/

// ��ʼ������
void InitArea(char (*area)[COLS], int rows, int cols, char element);

// ��ʾ����
void PrintArea(char(*show)[COLS], int row, int col);

// ������
void SetMine(char(*mine)[COLS], int row, int col);

// ��ʾ��Χ����
void SetShow(char(*mine)[COLS], char(*show)[COLS], int x, int y);

// �Ų���
void FindMine(char(*mine)[COLS], char(*show)[COLS], int row, int col);
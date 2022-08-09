#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<stdio.h>
#include<stdlib.h>

/*********************************************************************************/
/*								符号声明										*/
/*********************************************************************************/
#define ROW (9)
#define COL (9)

#define ROWS (ROW + 2)
#define COLS (COL + 2)

#define MINECOUNTS (10)


/*********************************************************************************/
/*								函数声明									 	 */
/*********************************************************************************/

// 初始化棋盘
void InitArea(char (*area)[COLS], int rows, int cols, char element);

// 显示区域
void PrintArea(char(*show)[COLS], int row, int col);

// 布置雷
void SetMine(char(*mine)[COLS], int row, int col);

// 显示周围雷数
void SetShow(char(*mine)[COLS], char(*show)[COLS], int x, int y);

// 排查雷
void FindMine(char(*mine)[COLS], char(*show)[COLS], int row, int col);
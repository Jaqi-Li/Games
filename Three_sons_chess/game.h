#pragma once
#include<stdio.h>
/*********************************************************************************/
/*								符号声明										*/
/*********************************************************************************/

#define ROW 5
#define COL 5

/*********************************************************************************/
/*								函数声明									 	 */
/*********************************************************************************/

// 初始化棋盘
void InitBoard(char (*board)[COL], int row, int col);

// 打印棋盘
void DisplayBoard(char(*board)[COL], int row, int col);

// 玩家下棋
void PlayerMove(char(*board)[COL], int row, int col);

// 电脑下棋
void ComputerMove(char(*board)[COL], int row, int col);

// 判断是否有一方赢了
char IsWin(char(*board)[COL], int row, int col);

// 判断棋盘是否满 0--未满；1--满
int IsFull(char(*board)[COL], int row, int col);
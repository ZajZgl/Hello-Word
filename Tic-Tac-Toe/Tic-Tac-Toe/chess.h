#pragma once
#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>


#define ROW 3
#define COL 3


int game();
void Menu();
void show_board(char board[ROW][COL], int row, int col);
void init_board(char board[ROW][COL], int row, int col);
void play_down(char board[ROW][COL], int row, int col);
void AI_down(char board[ROW][COL], int row, int col);
char who_win(char board[ROW][COL], int row, int col);

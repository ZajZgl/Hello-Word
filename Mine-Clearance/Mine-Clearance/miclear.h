#define _CRT_SECURE_NO_WARNINGS 1 
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

void menu();
void game();
void init_board_show(char board_show[ROWS][COLS], int rows, int cols);
void Show_board(char board_show[ROWS][COLS], int rows, int cols);

void init_board_booom(int board_boom[ROWS][COLS], int rows, int cols, int booms, int boom_list[][2]);
void show_boom(int board_boom[ROWS][COLS], int rows, int cols);

void init_board_clue(int board_clue[ROWS][COLS], int board_boom[ROWS][COLS], int rows, int cols);
void show_clue(int board_clue[ROWS][COLS], int rows, int cols);

int clear(int board_clue[ROWS][COLS], char board_show[ROWS][COLS]);
int judge_sucess(char board_show[ROWS][COLS], int board_clue[ROWS][COLS]);

void clear_board_1(int x, int y, char board_show[ROWS][COLS], int board_clue[ROWS][COLS]);
void clear_do(int x, int y, char board_show[ROWS][COLS], int board_clue[ROWS][COLS]);
void show_01(char board_show[ROWS][COLS], int board_clue[ROWS][COLS]);

void clear_do_0(int x, int y, char board_show[ROWS][COLS], int board_clue[ROWS][COLS]);
void clear_board_0(int x, int y, char board_show[ROWS][COLS], int board_clue[ROWS][COLS]);
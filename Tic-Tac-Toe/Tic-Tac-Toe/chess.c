#include "chess.h"
#include "time.h"
int game()
{
	char board[ROW][COL];
	init_board(board, ROW, COL);
	show_board(board, ROW, COL);
	char winer = 0;
	while (winer == 0)
	{
		printf("玩家走>\n");
		play_down(board, ROW, COL);
		show_board(board, ROW, COL);
		winer = who_win(board, ROW, COL);
		if (winer != 0)
		{
			printf("游戏结束\n");
			if (winer == 1)
			{
				printf("平局\n");
				return 0;
			}
			else if (winer == 'X')
			{
				printf("你赢了！！！\n");
				return 0;
			}
			else if (winer == 'O')
			{
				printf("你输了！！！\n");
				return 0;
			}
			else
				printf("出错\n");
		}
		printf("AI走>\n");
		AI_down(board, ROW, COL);
		show_board(board, ROW, COL);
		winer = who_win(board, ROW, COL);
		if (winer != 0)
		{
			printf("游戏结束\n");
			if (winer == 1)
			{
				printf("平局\n");
				return 0;
			}
			else if (winer == 'X')
			{
				printf("你赢了！！！\n");
				return 0;
			}
			else if (winer == 'O')
			{
				printf("你输了！！！\n");
				return 0;
			}
		}
	}
}
//判断输赢0:未结束  X:你赢  O:你输  1:平
char who_win(char board[ROW][COL], int row, int col)
{
	char flag_win = 0;
	for (int i = 0; i < row; i++)//判断行
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] && board[i][0] != ' ')
		{
			return board[i][0];
		}
	}
	for (int i = 0; i < col; i++)//判断列
	{
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i] && board[0][i] != ' ')
		{
			return board[0][i];
		}
	}
	//判断斜线
	if (board[1][1] == board[0][0] && board[1][1] == board[2][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	if (board[1][1] == board[2][0] && board[1][1] == board[0][2] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//平局判断
	int flag_ping = 1;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				flag_ping = 0;
		}

	}
	if (flag_ping == 1)
		flag_win = 1;
	return flag_win;
}
//玩家下棋
void play_down(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("玩家请输入坐标:\n");
		scanf("%d %d", &x, &y);
		//判断坐标是否合法
		if (board[x - 1][y - 1] == ' ' && x > 0 && x < row + 1 && y>0 && y < col + 1)
		{
			board[x - 1][y - 1] = 'X';
			break;
		}
		else
			printf("坐标不合法!\n");
	}
}
//AI下棋
void AI_down(char board[ROW][COL], int row, int col)
{
	srand((unsigned int)time(NULL));

	while (1)
	{
		int x = rand() % row;//0~(row-1)
		int y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = 'O';
			break;
		}
		else;
	}
}
//初始菜单
void Menu(void)
{
	printf("******************************\n");
	printf("*********   1.play   *********\n");
	printf("*********   0.exit   *********\n");
	printf("******************************\n");
}
//初始化棋盘
void init_board(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
//打印棋盘
void show_board(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		for (int j = 0; i < row - 1 && j < col; j++)
		{
			printf("---");
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
	}
}
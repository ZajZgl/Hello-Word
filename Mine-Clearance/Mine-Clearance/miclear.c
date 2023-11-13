#include "miclear.h"

void game()
{
	char board_show[ROWS][COLS];//表面显示图
	int board_boom[ROWS][COLS] = { 0 };//地雷图
	int board_clue[ROWS][COLS] = { 0 };//线索图
	int boom_list[20][2] = { 0 };//地雷坐标
	init_board_show(board_show,ROWS,COLS);
	init_board_booom(board_boom, ROWS, COLS,10, boom_list);
	init_board_clue(board_clue,board_boom,ROWS,COLS);
	int live = 1;
	while (live)
	{
		Show_board(board_show, ROWS, COLS);
		live = clear(board_clue, board_show);
		live = judge_sucess(board_show, board_clue);
	}
	show_clue(board_clue, ROWS, COLS);
}
//判断是否成功
int judge_sucess(char board_show[ROWS][COLS],int board_clue[ROWS][COLS])
{
	for (int i = 1; i < ROWS - 1; i++)
	{
		for (int j = 1; j < COLS - 1; j++)
		{
			if (board_show[i][j] == '*' && board_clue[i][j] != 9)
			{
				return 1;
			}
		}
	}
	printf("恭喜过关！！！\n");
	return 0;
}
//扫雷
int clear(int board_clue[ROWS][COLS], char board_show[ROWS][COLS])
{
	int x = 0;
	int y = 0;
	do 
	{
		printf("请输入坐标：");
		scanf("%d %d", &x, &y);
		if (x * y > 0 && x < ROWS - 1 && y < ROWS - 1 && board_show[x][y] == '*')
		{
			;
		}
		else
		{
			x = 0;
			printf("坐标错误，请重试\n");
		}
		
	} while (!(x * y));
	
	if (board_clue[x][y] == 9)//中弹
	{
		printf("失败！！！\n");
		return 0;
	}
	else//未中弹
	{
		clear_board_0(x,y,board_show,board_clue);
		return 1;
	}
}
//扫雷完毕显示区域
void clear_board_0(int x, int y, char board_show[ROWS][COLS], int board_clue[ROWS][COLS])
{
	printf("XXX");
	board_show[x][y] = board_clue[x][y] + 48;
	clear_board_1(x , y, board_show, board_clue);
	if(board_clue[x - 1][y]==0 && board_show[x - 1][y] != '0')
		clear_board_0(x-1, y, board_show, board_clue);
	if (board_clue[x + 1][y] == 0 && board_show[x + 1][y] != '0')
		clear_board_0(x + 1, y, board_show, board_clue);
	if (board_clue[x][y - 1] == 0 && board_show[x][y - 1] != '0')
		clear_board_0(x , y - 1, board_show, board_clue);
	if (board_clue[x][y + 1] == 0 && board_show[x][y + 1] != '0')
		clear_board_0(x , y + 1, board_show, board_clue);
	if (board_clue[x - 1][y + 1] == 0 && board_show[x - 1][y + 1] != '0')
		clear_board_0(x - 1, y + 1, board_show, board_clue);
	if (board_clue[x + 1][y + 1] == 0 && board_show[x + 1][y + 1] != '0')
		clear_board_0(x + 1, y + 1, board_show, board_clue);
	if (board_clue[x - 1][y - 1] == 0 && board_show[x - 1][y - 1] != '0')
		clear_board_0(x - 1, y - 1, board_show, board_clue);
	if (board_clue[x + 1][y - 1] == 0 && board_show[x + 1][y - 1] != '0')
		clear_board_0(x + 1, y - 1, board_show, board_clue);

	
	//if (board_clue[x - 1][y] < 2 && x - 1>0)//
	//	board_show[x - 1][y] = board_clue[x - 1][y] + 48;
	//if (board_clue[x + 1][y] < 2 && x + 1 < ROWS - 1)
	//	board_show[x + 1][y] = board_clue[x + 1][y] + 48;
	//if (board_clue[x][y - 1] < 2 && y - 1>0)
	//	board_show[x][y - 1] = board_clue[x][y - 1] + 48;
	//if (board_clue[x][y + 1] < 2 && y + 1 < COLS - 1)
	//	board_show[x][y + 1] = board_clue[x][y + 1] + 48;
	//if (board_clue[x - 1][y - 1] < 2 && x - 1>0 && y - 1 > 0)
	//	board_show[x - 1][y - 1] = board_clue[x - 1][y - 1] + 48;
	//if (board_clue[x - 1][y + 1] < 2 && x - 1>0 && y + 1 < COLS - 1)
	//	board_show[x - 1][y + 1] = board_clue[x - 1][y + 1] + 48;
	//if (board_clue[x + 1][y - 1] < 2 && x + 1 < ROWS - 1 && y - 1 > 0)
	//	board_show[x + 1][y - 1] = board_clue[x + 1][y - 1] + 48;
	//if (board_clue[x + 1][y + 1] < 2 && x + 1 < ROWS - 1 && y + 1 < COLS - 1)
	//	board_show[x + 1][y + 1] = board_clue[x + 1][y + 1] + 48;
}
void clear_board_1(int x, int y, char board_show[ROWS][COLS], int board_clue[ROWS][COLS])
{
	if (board_clue[x - 1][y] < 2 && x - 1>0)
		board_show[x - 1][y] = board_clue[x - 1][y] + 48;
	if (board_clue[x + 1][y] < 2 && x + 1 < ROWS - 1)
		board_show[x + 1][y] = board_clue[x + 1][y] + 48;
	if (board_clue[x][y - 1] < 2 && y - 1>0)
		board_show[x][y - 1] = board_clue[x][y - 1] + 48;
	if (board_clue[x][y + 1] < 2 && y + 1 < COLS - 1)
		board_show[x][y + 1] = board_clue[x][y + 1] + 48;
	if (board_clue[x - 1][y - 1] < 2 && x - 1>0 && y - 1 > 0)
		board_show[x - 1][y - 1] = board_clue[x - 1][y - 1] + 48;
	if (board_clue[x - 1][y + 1] < 2 && x - 1>0 && y + 1 < COLS - 1)
		board_show[x - 1][y + 1] = board_clue[x - 1][y + 1] + 48;
	if (board_clue[x + 1][y - 1] < 2 && x + 1 < ROWS - 1 && y - 1 > 0)
		board_show[x + 1][y - 1] = board_clue[x + 1][y - 1] + 48;
	if (board_clue[x + 1][y + 1] < 2 && x + 1 < ROWS - 1 && y + 1 < COLS - 1)
		board_show[x + 1][y + 1] = board_clue[x + 1][y + 1] + 48;
}
//初始化——线索图
void init_board_clue(int board_clue[ROWS][COLS],int board_boom[ROWS][COLS], int rows, int cols)
{
	for (int i = 1; i < rows-1; i++)
	{
		for (int j = 1; j < cols-1; j++)
		{
			if (board_boom[i][j] == 0)
			{
				board_clue[i][j] = board_boom[i - 1][j] + board_boom[i + 1][j] + board_boom[i][j - 1] + board_boom[i][j + 1] + board_boom[i-1][j-1]+ board_boom[i-1][j+1]+ board_boom[i+1][j-1]+ board_boom[i+1][j+1];
			}
			else
			{
				board_clue[i][j] = 9;
			}
		}
	}
}
//显示线索棋盘
void show_clue(int board_clue[ROWS][COLS], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("%d ", board_clue[i][j]);
		}
		printf("\n");
	}
}

//初始化——地雷棋盘
void init_board_booom(int board_boom[ROWS][COLS], int rows, int cols,int booms,int boom_list[][2])
{
	srand((unsigned)time(NULL));//生成随机数起点
	
	//生成地雷坐标
	for (int i = 0; i < booms; i++)
	{
		while (boom_list[i][0] == 0)
		{
			int x = (rand() % COL) + 1;
			int y = (rand() % ROW) + 1;
			if (x != boom_list[i][0] || y != boom_list[i][1])
			{
				boom_list[i][0] = x;
				boom_list[i][1] = y;
			}
		}
			
	}
	
	////地图置零
	//for (int i = 0; i < rows; i++)
	//{
	//	for (int j = 0; j < cols; j++)
	//	{
	//		board_boom[i][j] = 0;
	//	}
	//}
	//将地雷坐标导入地图
	for (int i = 0; i < booms; i++)
	{
		board_boom[ boom_list[i][0] ][ boom_list[i][1] ] = 1;
	}
}
//显示地雷地图
void show_boom(int board_boom[ROWS][COLS], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			printf("%d ", board_boom[i][j]);
		}
		printf("\n");
	}
}
//初始化——表面显示棋盘
void init_board_show(char board_show[ROWS][COLS],int rows,int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			board_show[i][j] = '*';
		}
	}
	for (int i = 0; i < cols ; i++)
	{
		board_show[0][i] =i;
		board_show[rows-1][i] =i;
		if (i == rows - 1)
		{
			board_show[rows - 1][i] = 0;
			board_show[0][i] = 0;
		}
	}
	for (int i = 0; i < rows ; i++)
	{
		board_show[i][0] =i;
		board_show[i][cols-1] =i;
		if (i == cols - 1)
		{
			board_show[i][cols-1] = 0;
			board_show[i][0] = 0;
		}
	}
}
//显示棋盘
void Show_board(char board_show[ROWS][COLS], int rows,int cols)
{

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (i == 0 || i == rows-1)
			{
				if (j > 9)
					printf("%d", board_show[i][j]);
				else
					printf("%d ", board_show[i][j]);
			}
			else if (j == 0 || j == cols - 1)
			{
				if (i > 9)
					printf("%d", board_show[i][j]);
				else
					printf("%d ", board_show[i][j]);
			}
			else
				printf("%c ", board_show[i][j]);
			
		}
		printf("\n");
	}
}
void menu()//菜单
{
	printf("**************************\n");
	printf("********  1.play  ********\n");
	printf("********  0.exit  ********\n");
	printf("**************************\n");
}
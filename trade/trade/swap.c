#include <stdio.h>//定义函数，交换两个变量的值

#include "swap.h"

#pragma comment(lib,"trade.lib")//导入静态库

int main()
{
	int a = 2;
	int b = 0;
	printf("%d %d\n", a, b);
	Swap(&a, &b);
	printf("%d %d\n", a, b);
	return 0;
}







//void Swap(int* x, int* y)//已储存在静态库
//{
//	int z = 0;
//	z = *x;
//	*x = *y;
//	*y = z;
//}
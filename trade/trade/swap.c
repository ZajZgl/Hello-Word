#include <stdio.h>//���庯������������������ֵ

#include "swap.h"

#pragma comment(lib,"trade.lib")//���뾲̬��

int main()
{
	int a = 2;
	int b = 0;
	printf("%d %d\n", a, b);
	Swap(&a, &b);
	printf("%d %d\n", a, b);
	return 0;
}







//void Swap(int* x, int* y)//�Ѵ����ھ�̬��
//{
//	int z = 0;
//	z = *x;
//	*x = *y;
//	*y = z;
//}
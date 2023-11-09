#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
//定义函数，交换两个变量的值
void Swap(int* x, int* y)
{
	int z = 0;
	z = *x;
	*x = *y;
	*y = z;
}
int main()
{
	int a = 2;
	int b = 0;
	printf("%d %d\n", a, b);
	Swap(&a,&b);
	printf("%d %d\n",a,b);
	return 0;
}

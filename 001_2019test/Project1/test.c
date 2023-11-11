#define _CRT_SECURE_NO_WARNINGS 1 
#include <stdio.h>
//汉诺塔
int a[5] = { 3,2,1,0 };
int b[5] = { 0 };
int c[5] = { 0 };
int bD = 0;
int aD = 3;
int cD = 0;//各堆的顶+1坐标

void Hanuot_printf()
{
	for (int i = 2; i >= 0; i--)
	{
		printf("%d %d %d\n", a[i], b[i], c[i]);
	}
	printf("\n");
	return 0;
}
void a_to_c()
{
	if (cD == 0 || c[cD - 1] > a[aD - 1])//c堆为空或c堆顶大于a堆顶
	{
		c[cD] = a[aD - 1];
		a[aD - 1] = 0;
		return 1;
	}
	else
		return 0;
}
void a_to_b()
{
	if (bD == 0 || b[bD - 1] > a[aD - 1])//c堆为空或c堆顶大于a堆顶
	{
		b[bD] = a[aD - 1];
		a[aD - 1] = 0;
		return 1;
	}
	else
		return 0;
}
void b_to_a()
{
	if (aD == 0 || a[aD - 1] > b[bD - 1])//c堆为空或c堆顶大于a堆顶
	{
		a[aD] = b[bD - 1];
		b[bD - 1] = 0;
		return 1;
	}
	else
		return 0;
}
void b_to_c()
{
	if (cD == 0 || c[cD - 1] > a[aD - 1])//c堆为空或c堆顶大于a堆顶
	{
		c[cD] = b[bD - 1];
		b[bD - 1] = 0;
		return 1;
	}
	else
		return 0;
}
void c_to_a()
{
	if (aD == 0 || a[aD - 1] > c[cD - 1])//c堆为空或c堆顶大于a堆顶
	{
		a[aD] = c[cD - 1];
		c[cD - 1] = 0;
		return 1;
	}
	else
		return 0;
}
void c_to_b()
{
	if (bD == 0 || b[bD - 1] > c[cD - 1])//c堆为空或c堆顶大于a堆顶
	{
		b[bD] = c[cD - 1];
		c[cD - 1] = 0;
		return 1;
	}
	else
		return 0;
}
void chack()
{
	for (int j = 0; j <= 3; j++)
	{
		if (a[j] == 0)
		{
			aD = j;
			break;
		}	
	}
	for (int j = 0; j <= 3; j++)
	{
		if (b[j] == 0)
		{
			bD = j;
			break;
		}	
	}
	for (int j = 0; j <= 3; j++)
	{
		if (c[j] == 0)
		{
			cD = j;
			break;
		}
	}
}



//int z = 0;//交换数值的中间变量
int main()
{	
	Hanuot_printf();
	while (1)
	{
		chack();
		char x, y;
		//清理缓存区
		int tmp = 0;
		scanf("%c %c", &x, &y);
		while ((tmp = getchar()) != '\n')
		{
			;
		}
		if (x == 'a')
		{
			if (y == 'b')
				a_to_b();
			if (y == 'c')
				a_to_c();
		}
		if (x == 'b')
		{
			if (y == 'a')
				b_to_a();
			if (y == 'c')
				b_to_c();
		}
		if (x == 'c')
		{
			if (y == 'a')
				c_to_a();
			if (y == 'b')
				c_to_b();
		}
		Hanuot_printf();
		if (c[2] == 1)
		{
			printf("恭喜你过关了！");
			break;
		}
			
	}
	return 0;
}

#include <stdio.h>

//int n_factorial(int n)//计算n的阶乘  n!
//{
//	for (int i = n-1; i > 0; i--)
//	{
//		n *= i;
//	}
//	return n;
//}
//int n_factorial_2(int n)//计算1！+2！+3！+...+n!
//{
//	for (int i = n-1; i > 0; i--)
//	{
//		n += n_factorial(i);
//	}
//	return n;
//}
/*******************************************************/
//int x_find(int x, int a[], int len)//二分法，在有序数组a[]中寻找x
//{
//	len -= 1;
//	int f = (len) / 2;
//	do
//	{
//		if (a[f] > x)
//		{
//			f /= 2;
//		}
//		else if (a[f] < x)
//		{
//			f += (len - f) / 2;
//			if ((len - f) == 1)
//			{
//				f = len;
//			}
//		}
//		else if (a[f] == x)
//			break;
//	} while (a[f] != x && f != 0 && f < len);
//	if (a[f] == x)
//		return a[f];
//	else
//		return 0;
//}
//int main()
//{
//	int a[] = { 1,2,3,4,5,6,7,8,9 };
//	int n_len = sizeof(a) / sizeof(a[0]);//求元素个数，不能写在自定义函数内部，因为数组名只是储存了第一位成员的地址
//	printf("%d\n", x_find(1, a, n_len));
//	return 0;
//}
/************************************************/
//void code_1()//使文字从中间慢慢出现
//{
//	char a1[] = "Hello I am ZGL!!!";
//	char a2[] = "#################";
//	int left = 0;
//	int right=strlen(a1)-1;
//	for (int i=0; left + i <= right -i;i++)
//	{
//		for (int j = 0; j < left + i; j++)
//			printf("%c", a1[j]);
//		for (int j =left + i; j < right - i;j++)
//			printf("%c", a2[j]);
//		for (int j = right - i; j < right; j++)
//			printf("%c", a1[j]);
//		printf("\n");
//	}
//}
/*************************************************************/
//#include <stdio.h>//连续多次生成随机数
//#include <time.h>
//int main()
//{
//	srand((unsigned int)time(NULL));//只调用一次
//	while (1) 
//	{
//		int a = rand()%100;//限制在0-100
//		if (getchar() != '0')
//		{
//			printf("%d", a);
//		}
//		else
//		{
//			return 0;
//		}
//	}
//	return 0;
//}
/****************************************************/
//#include <stdio.h>//定义函数，交换两个变量的值
//void Swap(int* x, int* y)
//{
//	int z = 0;
//	z = *x;
//	*x = *y;
//	*y = z;
//}
//int main()
//{
//	int a = 2;
//	int b = 0;
//	printf("%d %d\n", a, b);
//	Swap(&a, &b);
//	printf("%d %d\n", a, b);
//	return 0;
//}
/************************************************/
////函数递归_数数
//void count_n(unsigned int n)
//{
//	if (n > 0)//限制条件
//	{
//		count_n(n - 1);//使变量接近限制条件
//	}
//	printf("%d\n", n);
//}
//int main()
//{
//	count_n(100);
//	return 0;
//}
/***************************************************/
////函数递归_数字符
//int strlen_my(char* s)
//{
//	if (*s != '\0')
//		return 1 + strlen_my(s + 1);
//	else
//		return 0;
//}
//
//int main()
//{
//	printf("%d", strlen_my("ananana"));
//	return 0;
//}
/****************************************/
////函数递归_求阶乘
//int n_factorial(int n)
//{
//	if (n != 0)
//		return n * n_factorial(n - 1);
//	else
//		return 1;
//}
//
//int main()
//{
//	printf("%d", n_factorial(3));
//	return 0;
//}
/******************************************/
////计算第n个斐波那契数（1,1,2,3,5,8,13...）
//int Fib_n(int n)
//{
//	int a = 1;
//	int b = 1;
//	int c = 1;
//	while (n > 2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}
//
//int main()
//{
//	printf("%d", Fib_n(10));
//	return 0;
//}
/*****************************************/
////汉诺塔
//#define _CRT_SECURE_NO_WARNINGS 1 
//#include <stdio.h>
//int a[5] = { 3,2,1,0 };
//int b[5] = { 0 };
//int c[5] = { 0 };
//int bD = 0;
//int aD = 3;
//int cD = 0;//各堆的顶+1坐标
//
//void Hanuot_printf()
//{
//	for (int i = 2; i >= 0; i--)
//	{
//		printf("%d %d %d\n", a[i], b[i], c[i]);
//	}
//	printf("\n");
//	return 0;
//}
//void a_to_c()
//{
//	if (cD == 0 || c[cD - 1] > a[aD - 1])//c堆为空或c堆顶大于a堆顶
//	{
//		c[cD] = a[aD - 1];
//		a[aD - 1] = 0;
//		return 1;
//	}
//	else
//		return 0;
//}
//void a_to_b()
//{
//	if (bD == 0 || b[bD - 1] > a[aD - 1])//c堆为空或c堆顶大于a堆顶
//	{
//		b[bD] = a[aD - 1];
//		a[aD - 1] = 0;
//		return 1;
//	}
//	else
//		return 0;
//}
//void b_to_a()
//{
//	if (aD == 0 || a[aD - 1] > b[bD - 1])//c堆为空或c堆顶大于a堆顶
//	{
//		a[aD] = b[bD - 1];
//		b[bD - 1] = 0;
//		return 1;
//	}
//	else
//		return 0;
//}
//void b_to_c()
//{
//	if (cD == 0 || c[cD - 1] > a[aD - 1])//c堆为空或c堆顶大于a堆顶
//	{
//		c[cD] = b[bD - 1];
//		b[bD - 1] = 0;
//		return 1;
//	}
//	else
//		return 0;
//}
//void c_to_a()
//{
//	if (aD == 0 || a[aD - 1] > c[cD - 1])//c堆为空或c堆顶大于a堆顶
//	{
//		a[aD] = c[cD - 1];
//		c[cD - 1] = 0;
//		return 1;
//	}
//	else
//		return 0;
//}
//void c_to_b()
//{
//	if (bD == 0 || b[bD - 1] > c[cD - 1])//c堆为空或c堆顶大于a堆顶
//	{
//		b[bD] = c[cD - 1];
//		c[cD - 1] = 0;
//		return 1;
//	}
//	else
//		return 0;
//}
//void chack()
//{
//	for (int j = 0; j <= 3; j++)
//	{
//		if (a[j] == 0)
//		{
//			aD = j;
//			break;
//		}
//	}
//	for (int j = 0; j <= 3; j++)
//	{
//		if (b[j] == 0)
//		{
//			bD = j;
//			break;
//		}
//	}
//	for (int j = 0; j <= 3; j++)
//	{
//		if (c[j] == 0)
//		{
//			cD = j;
//			break;
//		}
//	}
//}
//
//
//
////int z = 0;//交换数值的中间变量
//int main()
//{
//	Hanuot_printf();
//	while (1)
//	{
//		chack();
//		char x, y;
//		//清理缓存区
//		int tmp = 0;
//		scanf("%c %c", &x, &y);
//		while ((tmp = getchar()) != '\n')
//		{
//			;
//		}
//		if (x == 'a')
//		{
//			if (y == 'b')
//				a_to_b();
//			if (y == 'c')
//				a_to_c();
//		}
//		if (x == 'b')
//		{
//			if (y == 'a')
//				b_to_a();
//			if (y == 'c')
//				b_to_c();
//		}
//		if (x == 'c')
//		{
//			if (y == 'a')
//				c_to_a();
//			if (y == 'b')
//				c_to_b();
//		}
//		Hanuot_printf();
//		if (c[2] == 1)
//		{
//			printf("恭喜你过关了！");
//			break;
//		}
//
//	}
//	return 0;
//}
/******************************************/



#include <stdio.h>

int n_factorial(int n)//计算n的阶乘  n!
{
	for (int i = n-1; i > 0; i--)
	{
		n *= i;
	}
	return n;
}
int n_factorial_2(int n)//计算1！+2！+3！+...+n!
{
	for (int i = n-1; i > 0; i--)
	{
		n += n_factorial(i);
	}
	return n;
}
//int x_find(int x,int a[])//二分法，在有序数组a[]中寻找x
//{
//	int n_len = sizeof(a) / sizeof(a[0]);
//	int f = n_len / 2;
//
//	while (a[f] != x)
//	{
//		if (a[f] > x)
//		{
//			f /= 2;
//		}
//		else if (a[f] < x)
//		{
//			f += (n_len - f) / 2;
//		}
//		else if (a[f] = x)
//			return a[f];
//	}
//}
void code_1()
{
	char a1[] = "Hello I am ZGL!!!";
	char a2[] = "#################";
	int left = 0;
	int right=strlen(a1)-1;
	for (int i=0; left + i <= right -i;i++)
	{
		for (int j = 0; j < left + i; j++)
			printf("%c", a1[j]);
		for (int j =left + i; j < right - i;j++)
			printf("%c", a2[j]);
		for (int j = right - i; j < right; j++)
			printf("%c", a1[j]);
		printf("\n");
	}
}



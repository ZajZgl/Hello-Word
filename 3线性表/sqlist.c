#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sqlist.h"
/*
 *list_create:init the list ,apply for memory.
 * */
sqlink list_create()
{
	sqlink L;
	L = (sqlink)malloc(sizeof(sqlist));//申请内存空间
	if (L == NULL)
	{
		printf("list malloc failed\n");
		return L;
	}
	memset(L,0,sizeof(sqlist));//初始化为0
	L->last = -1;
	return L;
}
/*
 * list_clear:reset the list to 0.
 *@ret 0-success  -1-filed
 * */
int list_clear(sqlink L)
{
	if(L == NULL)
		return -1;

	memset(L,0,sizeof(sqlist));//重置为0
	L->last = -1;
	return 0;
}
/*
 * list_empty: The list is empty or not.    函数功能
 * para L:list 							  	参数
 * @ret  1-empty   0-not empty 				返回值
 * */
int list_empty(sqlink L)
{
	if(L->last == -1)
		return 1;
	else
		return 0;
}
/*
 *list_length:get the list length.
 * */
int list_length(sqlink L)
{
	if(L->last == -1||L == NULL)
		return 0;
	else
		return (L->last + 1);
}
int list_inster(sqlink L,data_t value,int pos)
{
	//check full
	if(L->last == N-1)
	{
		printf("the list is full !!!\n");
		return -1;
	}
	//check pos in [0,last+1]
	 if(pos < 0 || pos > L->last + 1)
	{
		printf("the pos is invalid\n");
		return -1;
	}
	//move
	int i=0;
	for(i = L->last;i >= pos;i--)
	{
		L->data[i+1] = L->data[i];
	}
	L->last++;
	L->data[pos] = value;
	return 0;
}

int list_dispaly(sqlink L)
{
	if(L->last == -1)
	{
		printf("the list is empty !!!\n");
		return -1;
	}
	int i = 0;
	for(i = 0;i <= L->last;i++)
	{
		printf("%d ",L->data[i]);
	}
	printf("\n");
	return 0;
}
int list_free(sqlink L)
{
	if(L == NULL)
		return -1;
	free(L);
	L = NULL;
	return 0;
}

int list_delete(sqlink L,int pos)
{
	if(L->last == -1)
	{
		printf("the list is empty !!!\n");
		return -1;
	}
	//check pos in [0,last]
	 if(pos < 0 || pos > L->last)
	{
		printf("the pos is invalid\n");
		return -1;
	}
	//move
	int i=0;
	for(i = pos;i <= L->last;i++)
	{
		L->data[i] = L->data[i+1];
	}
	L->last--;
	return 0;
}
int list_merge(sqlink La,sqlink Lb)
{
	//La,Lb not empty
	if(La->last == -1 || Lb->last == -1)
	{
		printf("La or Lb is empty !!!");
		return -1;
	}
	//merge
	int ai = 0;
	int bi = 0;
	int z = 0;
	for(bi = 0;bi <= Lb->last;bi++)
	{
		z = 0;
		for(ai = 0;ai <= La->last;ai++)
		{
			if(La->data[ai] == Lb->data[bi])
			{
				z = 1;
				break;
			}
		}
		if(z == 0)
			list_inster(La,Lb->data[bi],La->last+1);
	}
	return 0;
}
int list_remove_duplicate(sqlink L)
{
	//empty?
	if(L->last == -1)
	{
		printf("list is empty !!!");
		return -1;
	}
	//remove duplicate
	int i = 0;
	int j = 0;
	for(i = 1;i <= L->last;i++)
	{
		for(j = 0;j < i;j++)
		{
			if(L->data[i] == L->data[j])
			{
				list_delete(L,i);
				i--;
			}
		}
	}
	return 0;
}

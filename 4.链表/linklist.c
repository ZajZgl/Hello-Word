#include <stdio.h>
#include "linklist.h"
#include <stdlib.h>

linklist linklist_create()
{
	linklist H;
	H = (linklist)malloc(sizeof(listnode));
	if(H == NULL)
	{
		printf("malloc failed\n");
		return H;
	}
	H->data = 0;
	H->next = NULL;

	return H;
}
int linklist_tail_insert(linklist H,data_t value)
{
	linklist P;
	linklist q;
	if(H == NULL)
	{
		printf("H == NULL");
		return -1;
	}
	//1 new node P
	if ((P = (linklist)malloc(sizeof(listnode))) == NULL)
	{
		printf("malloc failed\n");
		return -1;
	}
	P->data = value;
	P->next = NULL;

	//2 tail node
	q = H;
	while(q->next != NULL)
	{
		q = q->next;
	}

	//3 insert
	q->next = P;

	return 0;
}
int linklist_display(linklist H)
{
	if(H == NULL)
	{
		printf("H is NULL\n");
		return -1;
	}
	while(H->next != NULL)
	{
		H = H->next;
		printf("%d ",H->data);
	}
	puts("");
	return 0;
}

linklist linklist_get(linklist H,int pos)
{
	linklist p;
	int i;
	if(H == NULL)
	{
		printf("H is NULL");
		return NULL;
	}
	if(pos == -1)
	{
		return H;
	}

	p = H;
	i = -1;
	while(i < pos)
	{
		i++;
		p = p->next;
		if(p == NULL)
		{
			printf("pos is invalid\n");
			return NULL;
		}
	}
	return p;
}

int linklist_insert(linklist H,data_t value,int pos)
{
	linklist new;
	linklist p;
	if(H == NULL)
	{
		printf("H is NULL\n");
		return -1;
	}
	//1 locate note p
	p = linklist_get(H,pos-1);
	if(p == NULL)
	{
		printf("p is NULL\n");
		return -1;
	}
	//2 new node new
	if((new = (linklist)malloc(sizeof(listnode))) == NULL)
	{
		printf("malloc failed\n");
		return -1;
	}
	new->data = value;
	
	//3 insert
	new->next = p->next;
	p->next = new;

	return 0;
}


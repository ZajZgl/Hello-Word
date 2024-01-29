#include <stdio.h>
#include "linklist.h"

void test_linklist_get();
void test_linklist_tail_insert();
void test_linklist_insert();
int main(int argc, const char *argv[])
{
	//test_linklist_tail_insert();
	//test_linklist_get();
	test_linklist_insert();
	return 0;
}
void test_linklist_insert()
{
	linklist H;
	linklist p;
	H = linklist_create();
	linklist_tail_insert(H,10);
	linklist_tail_insert(H,20);
	linklist_tail_insert(H,30);
	linklist_tail_insert(H,40);
	linklist_tail_insert(H,50);
	linklist_tail_insert(H,60);
	linklist_display(H);
	linklist_insert(H,1000,0);
	linklist_display(H);
	return;
}
void test_linklist_get()
{
	linklist H;
	linklist p;
	H = linklist_create();
	linklist_tail_insert(H,10);
	linklist_tail_insert(H,20);
	linklist_tail_insert(H,30);
	linklist_tail_insert(H,40);
	linklist_tail_insert(H,50);
	linklist_tail_insert(H,60);
	linklist_display(H);
	p = linklist_get(H,6);
	if(p != NULL)
		printf("%d\n",p->data);
	
	return;
}
void test_linklist_tail_insert()
{
	linklist H;
	int value;

	H = linklist_create();
	if(H == NULL)
		return;

	printf("input:");
	while(1)
	{
		scanf("%d",&value);
		if(value == -1)
			break;
		linklist_tail_insert(H,value);
		printf("input:");
	}
	linklist_display(H);
	return;
}

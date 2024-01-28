#include <stdio.h>
#include "sqlist.h"
void test_merge();
void test_remove_duplicate();
int main(int argc, const char *argv[])
{
	test_remove_duplicate();
	//test_merge();
	return 0;
}
void test_remove_duplicate()
{
	sqlink L;
	L = list_create();
	
	list_inster(L,9,0);
	list_inster(L,9,0);
	list_inster(L,8,0);
	list_inster(L,7,0);
	list_inster(L,7,0);
	list_inster(L,8,0);
	list_inster(L,7,0);
	list_inster(L,7,0);
	list_inster(L,5,0);
	list_dispaly(L);	
	printf("****************\n");
	list_remove_duplicate(L);
	list_dispaly(L);
	list_free(L);

}
void test_merge()
{
	sqlink L,L2;
	L = list_create();
	L2 = list_create();
	
	list_inster(L,9,0);
	list_inster(L,8,0);
	list_inster(L,7,0);
	list_inster(L,6,0);
	list_inster(L,5,0);
	list_inster(L,4,0);
	list_inster(L,3,0);
	list_inster(L,2,0);
	list_inster(L,1,0);
	list_inster(L2,9,0);
	list_inster(L2,88,0);
	list_inster(L2,6,0);
	list_inster(L2,96,0);
	
	list_dispaly(L);	
	list_dispaly(L2);	
	
	list_merge(L,L2);

	list_dispaly(L);
	list_dispaly(L2);	

	list_free(L);
	list_free(L2);
	return;
}

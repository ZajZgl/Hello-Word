#include <stdio.h>
#include "add.h"
#include "sub.h"

int main(int argc, const char *argv[])
{
	int a = 3, b = 5;
	int ret;

	ret = add_fun(a, b);
	printf("add %d\n",ret);

	ret = sub(a, b);
	printf("sub %d\n",ret);

	printf("*********\n");
	return 0;
}

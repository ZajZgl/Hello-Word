#include "miclear.h"

int main()
{
	int input = 0;
	do 
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("�������������");
			break;
		}
	} while (input);
	
	return 0;
}

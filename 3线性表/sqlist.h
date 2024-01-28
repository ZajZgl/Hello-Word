
typedef int data_t;
#define N 128

//方式1
typedef struct
{
	data_t data[N];
	int last;
}sqlist, * sqlink;

sqlink list_create();
int list_dispaly(sqlink L);
int list_clear(sqlink L);
int list_empty(sqlink L);
int list_length(sqlink L);
int list_inster(sqlink L,data_t value,int pos);
int list_free(sqlink L);
int list_delete(sqlink L,int pos);
int list_merge(sqlink La,sqlink Lb);

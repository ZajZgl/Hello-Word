typedef int data_t;

typedef struct node
{
	data_t data;
	struct node * next;
}listnode, * linklist;

linklist linklist_create();
int linklist_tail_insert(linklist H,data_t value);
int linklist_display(linklist H);
linklist linklist_get(linklist H,int pos);
int linklist_insert(linklist H,data_t value,int pos);

#include <stdio.h>
#include <stdlib.h>

typedef struct ele{
	int data;
	struct ele *next;
}ll;

void insert_at_first(ll **tail,int data);
void insert_at_last(ll **tail,int data);
void display(ll **tail);
void create_loop(ll **tail,int pos);
int ll_len(ll **tail);
void detect_loop(ll **tail,int remove_loop);


int main()
{
	ll *tail = NULL;
	insert_at_first(&tail,5);
	insert_at_first(&tail,7);
	insert_at_last(&tail,9);
	insert_at_last(&tail,27);
	create_loop(&tail,2);
	detect_loop(&tail,1);
	display(&tail);


}

void insert_at_first(ll **tail,int data)
{
	ll *node = (ll*)malloc(sizeof(ll));

	if(!node)
	{
		printf("Failed to allocate memory\n");
	}
	else
	{
		node->data = data;
		if(*tail == NULL)
		{
			node->next = node;
			*tail = node;
		}
		else
		{
			node->next = (*tail)->next;
			(*tail)->next = node;
		}
	}
}

void insert_at_last(ll **tail,int data)
{
	ll *node = (ll *)malloc(sizeof(ll));
	if(!node)
	{
		printf("Failed to allocate memory\n");
	}
	else
	{
		node->data = data;
		if(*tail == NULL)
		{
			*tail = node;
			node->next = node;
		}
		else
		{
			node->next = (*tail)->next;
			(*tail)->next = node;
			*tail = node;
		}
	}
}

int ll_len(ll **tail)
{
	ll *temp = *tail;
	int len = 0;
	do{
		temp = temp->next;
		len++;
	}while(temp != *tail);
	return len;
}

void create_loop(ll **tail,int pos)
{
	int len = ll_len(tail);
	int i=0;
	ll *temp = *tail;
	ll *head = (*tail)->next;
	while(pos <= len)
	{
		if(i == pos)
		{
			(*tail)->next = temp;
			*tail = head; 
			return;
		}
		i++;
		temp = temp->next;
	}
	printf("Loop created\n******************************\n\n\n");
}

void detect_loop(ll **tail,int remove_loop)
{
	ll *fast_ptr = *tail;
	ll *slow_ptr = *tail;

	do
	{
		fast_ptr = fast_ptr->next->next;
		slow_ptr = slow_ptr->next;
	}while(fast_ptr != slow_ptr);

	ll *temp = *tail;
	ll *prev = NULL;

	while(temp != slow_ptr)
	{
		temp = temp->next;
		prev = slow_ptr;
		slow_ptr = slow_ptr->next;
	}
	printf("Loop started at node with data :%d\n",temp->data);

	if(remove_loop == 1)
	{
		prev->next = *tail;
		*tail = prev;
	}
}


void display(ll **tail)
{
	if(*tail == NULL)
	{
		printf("Linked list is empty\n");
	}
	else
	{
		ll *temp = *tail;
		do{
			printf("%d\n",temp->data);
			temp = temp->next;
		}while(temp != *tail);
	}
}


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

int main()
{
	ll *tail = NULL;
	insert_at_first(&tail,5);
	insert_at_first(&tail,7);
	insert_at_last(&tail,9);
	insert_at_last(&tail,27);
	create_loop(&tail,2);
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
	while(temp)
	{
		temp = temp->next;
		len++;
	}
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
			temp = temp->next;
		}
		i++;
		(*tail)->next = temp;
		*tail = head; 
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


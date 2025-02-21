#include<stdio.h>
#include<stdlib.h>

struct tnode
{
	int x;
	tnode *next;
	tnode *prev;
}*head, *tail;

void push_front(int value)
{
	struct tnode *node = (tnode*) malloc(sizeof(tnode));
	node->x = value;
	
	if(head==NULL)
	{
		node ->next = NULL;
		node ->prev = NULL;
		head = tail = node;
	}
	else
	{
		node->next = head;
		node->prev = NULL;
		head ->prev = node;
		head = node;
	}
}

void push_back(int value)
{
	struct tnode *node = (tnode*) malloc(sizeof(tnode));
	node->x = value;
	
	if(head==NULL)
	{
		node ->next = NULL;
		node ->prev = NULL;
		head = tail = node;
	}
	else
	{
		node->prev = tail;
		node->next = NULL;
		tail->next = node;
		tail = node;
	}
}

void push_mid(int value, int searchKey)
{
	struct tnode *node = (tnode*) malloc(sizeof(tnode));
	node->x = value;
	
	if(head == NULL)
	{
		node ->next = NULL;
		node ->prev = NULL;
		head = tail = node;
	}
	else
	{
		struct tnode *curr_front = head;
		struct tnode *curr_back = tail;
		while(curr_front->x != searchKey && curr_front != NULL)curr_front = curr_front->next;
//		while(curr_back->x != searchKey && curr_back->x != NULL)curr_back = curr_back->prev;

		if(curr_front == NULL){
			printf("Data %d is not found in the linked list\n", searchKey);
		}
		node->next = curr_front->next;
		node->prev = curr_front;
		curr_front->next = node;
		
		if(node->next != NULL){
			node->next->prev = node;
		}
		else{
			push_back(value);
		}
	}
}

void delete_front()
{
	if(head==NULL)
	{
		printf("There is no data\n");
	}
	else
	{
		if(head==tail)
		{
			free(head);
			head = tail = NULL;
		}
		else
		{
			struct tnode *del = head;
			head = head->next;
			head->prev = NULL;
			free(del);
		}
	}
}

void delete_back()
{
	if(tail==NULL)
	{
		printf("There is no data\n");
	}
	else
	{
		if(tail==head)
		{
			free(head);
			head = tail = NULL;
		}
		else
		{
			struct tnode *del = tail;
			tail = tail->prev;
			tail->next = NULL;
			free(del);
		}
	}
}

void delete_mid(int searchKey)
{
	if(head==NULL)
	{
		printf("There is no data\n");
	}
	else
	{
		if(head == tail)
		{
			free(head);
			head = tail = NULL;
		}
		else
		{
			struct tnode *del = head;
			while(del->x != searchKey && del != NULL)del = del->next;
			
			if(del == NULL){
				printf("Data %d is not found in the linked list\n", searchKey);
				return;
			}
			if(del->next == NULL){
				delete_back();
				return;
			}
			if(del->prev == NULL){
				delete_front();
				return;
			}
			
			del->prev->next = del->next;
			del->next->prev = del->prev;
			free(del);
		}
	}
	
}

void print_linked()
{
	if (head==NULL)
	{
		printf("List kosong\n");
		return;
	}
	
	struct tnode *curr = head;
	
	while(curr!=NULL)
	{
		printf("%d ", curr->x);
		curr = curr->next;
	}
}

void print_reverse()
{
	if (head==NULL)
	{
		printf("List kosong\n");
		return;
	}
	
	struct tnode *curr = tail;
	
	while(curr!=NULL)
	{
		printf("%d ", curr->x);
		curr = curr->prev;
	}
}

int main()
{
	printf("Linked list\n");
	push_front(4);
	push_front(5);
	push_mid(2,5);
	push_mid(3,2);
	push_back(3);
	print_linked();getchar();
	print_reverse();getchar();
	delete_mid(3);
	print_linked();getchar();
	print_reverse();getchar();
	return 0;
}


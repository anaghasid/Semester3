// ALL FUNCTIONS WORKING
#include"dll.h"
#include <stdio.h>
#include <stdlib.h>
 
list_t* create_list()  // return a newly created empty doubly linked list
{
	// DO NOT MODIFY!!!
	list_t* l = (list_t*) malloc(sizeof(list_t));
	l->head = NULL;
	l->tail = NULL;
	l->size = 0;
	return l;
}

void insert_front(list_t* list, int data)  // TODO: inserts data to the beginning of the linked list
{
    node_t* newnode = (node_t*)malloc(sizeof(node_t));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;

    if(is_empty(list))
    {
        list->head = newnode;
        list->tail = newnode;
        list->size++;
        return;
    }
    list->head->prev = newnode;
    newnode->next = list->head;
    list->head = newnode;
    list->size++;
}

void insert_back(list_t* list, int data) // TODO: inserts data to the end of the linked list
{
    node_t* newnode = (node_t*)malloc(sizeof(node_t));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    if(list->head==NULL)
    {
        list->head = newnode;
        list->tail = newnode;
        list->size++;
        return;
    }
    newnode->prev = list->tail;
    list->tail->next = newnode;
    list->tail = newnode;
    list->size++;
}

void insert_after(list_t* list, int data, int prev) // TODO: inserts data after the node_t with data “prev”. Do not insert or do anything if prev doesn't exist
{
    node_t* cur = list->head;
    node_t* newnode = (node_t*)malloc(sizeof(node_t));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    while(cur!=NULL)
    {
        if(cur->data==prev)
        {
            newnode->prev = cur;
            newnode->next = cur->next;
            newnode->next->prev = newnode;
            cur->next = newnode;
            list->size++;
            return;
        }
        cur = cur->next;
    }
    
}

void delete_front(list_t* list) 
{
    node_t* temp = list->head;
    list->head = list->head->next;
    list->head->prev = NULL;
    list->size--;
    free(temp);     // POTENTIAL PROBLEM POINT
}

void delete_back(list_t* list) 
{
    list->tail = list->tail->prev;
    list->tail->next = NULL;
    list->size--;
}

void delete_node(list_t* list, int data) // TODO: delete the node_t with “data” from the linked list.
{
    node_t* cur = list->head;
    while(cur!=NULL)
    {
        if(cur->data==data)
        {
            if(cur==list->head)
            {
                delete_front(list);
                return;
            }
            if(cur==list->tail)
            {
                delete_back(list);
                return;
            }
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            list->size--;
            return;
        }
        cur = cur->next;
    }
}

node_t* search(list_t* list, int data) // TODO: returns the pointer to the node_t with “data” field. Return NULL if not found.
{	
    node_t* cur = list->head;
    while(cur!=NULL)
    {
        if(cur->data==data)
        {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

int is_empty(list_t* list) // return true or 1 if the list is empty; else returns false or 0
{
	// DO NOT MODIFY!!!
	return list->size == 0;
}

int size(list_t* list) // returns the number of nodes in the linked list.  
{
	// DO NOT MODIFY!!!
	return list->size;
}

void delete_nodes(node_t* head) // helper
{
	// DO NOT MODIFY!!!
	if(head == NULL)
		return;
	delete_nodes(head->next);
	free(head);	
}

void delete_list(list_t* list) // free all the contents of the linked list
{
	// DO NOT MODIFY!!!
	delete_nodes(list->head);
	free(list);
}

void display_list(list_t* list) // print the linked list by separating each item by a space and a new line at the end of the linked list.
{
	// DO NOT MODIFY!!!
	node_t* it = list->head;
	while(it != NULL)
	{
		printf("%d ", it->data);
		it = it->next;
	}
	printf("\n");
}

/*
int main()
{
	list_t *l;
	l=create_list();
    printf("created\n");
	insert_front(l,10);
	printf("check\n");
	display_list(l);
	insert_front(l,5);
	display_list(l);
    // printf("Done displaying\n");
	insert_back(l,20);
	display_list(l);
	insert_back(l,30);
	display_list(l);
	insert_after(l,83,20);
	display_list(l);
	delete_front(l);
	display_list(l);
	delete_back(l);
	display_list(l);
	delete_node(l,20);
	display_list(l);
}*/
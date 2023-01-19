// Double Ended Queue using linked lists

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    int ele;
    struct node* link;
};
typedef struct node node;

struct point
{
    struct node* front;
    struct node* rear;
};
typedef struct point point;

point *createlist(point *head)
{
    head->front=NULL;
    head->rear = NULL;
    return head;
}

point *insertFront(point *head,int ele)
{
    node *newnode=(node*)malloc(sizeof(node)); //creating a new node so head points to that and that again points to first ele
    newnode->ele=ele;
    newnode->link=NULL;

    if(head->front==NULL){
        head->front = newnode;
        head->rear = newnode;
    }
    else
    {
        newnode->link=head;
        head->front=newnode;
    }
    return head;
}

point *insertRear(point *head, int ele)
{
    node *newnode=(node*)malloc(sizeof(node)); //creating a new node so head points to that and that again points to first ele
    newnode->ele=ele;
    newnode->link=NULL;   
    if(head->front==NULL)
    {
    head->front = newnode;
    head->rear = newnode;
    }
    else
    {
        head->rear->link = newnode;
        head->rear = newnode;
    }
}


void display(point* head)
{
    node *pres = head->front;
    while(pres!=NULL)
    {
        printf("%d\t",pres->ele);
        pres = pres->link;
    }
    printf("\n");
}
 int main()
{
    
}

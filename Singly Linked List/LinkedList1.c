#include<stdio.h>
#include<stdlib.h>
#include"ll1.h"

Node *createlist(Node *head)
{
    head=NULL;
    return head;
}
Node *InsertFront(Node *head,int ele)
{
    Node *newnode=(Node*)malloc(sizeof(Node)); //creating a new node so head points to that and that again points to first ele
    newnode->data=ele;
    newnode->link=NULL;

    if(head==NULL){
        head=newnode;
    }
    else{
        newnode->link=head;
        head=newnode;
    }
    return head;
}

Node *InsertRear(Node *head,int ele)
{
    Node *newnode=NULL,*cur; //creating a new node so head points to that and that again points to first ele
    newnode=(Node *)malloc(sizeof(Node));
    newnode->data=ele;
    newnode->link=NULL;

    cur=head;
    if(head==NULL){
        head=newnode;
    }
    else{
        while(cur->link!=NULL)
            cur=cur->link;
        cur->link=newnode;
    }
    return head;
}
Node *Insertatpos(Node *head,int ele,int pos)
{
    Node* newnode = NULL;
    newnode=(Node*)malloc(sizeof(Node));
    newnode->data=ele;
    newnode->link=NULL;
    Node* cur =head;
    if(pos==1)  // position starts with 1 not 0
    {
        head=InsertFront(head,ele);
    }
    else
    {
            if(head==NULL){
                printf("\n Invalid Position..Cannot insert\n");
                return head;
            }
            newnode=(Node *)malloc(sizeof(Node));
            newnode->data=ele;
            newnode->link=NULL;

            for(int i=1;i<pos-1;i++)
            {
                cur=cur->link;
                if(cur==NULL)
                {
                    printf("Invalid position\n");
                    free(newnode);
                    return head;
                }
                else
                {
                    newnode->link = cur->link;
                    cur->link = newnode;    
                    return head;
                }
            }
    }
}


void Display(Node* head)
{
    Node* pres = head;
    while(pres!=NULL)
    {
        printf("%d\t",pres->data);
        pres = pres->link;
    }
    printf("\n");
}

Node* deleteFront(Node* head)
{
    Node *cur=head;
    printf("Deleted %d",cur->data);
    head=head->link;
    free(cur);
    return head;
}

void deleteRear(Node* head)
{
    Node* pres = head;
    Node* prev;
    while(pres->link!=NULL)
    {
        prev = pres;
        pres=pres->link;
    }
    printf("Deleted %d\n",pres->data);
    free(pres);
    prev->link = NULL;
}

void deleteAlt(Node* head)
{
    Node* pres = head;
    Node* prev = NULL;
    Node* temp;
    while(pres!=NULL)
    {
        prev = pres;
        pres = pres->link;
        pres = pres->link;
        temp = prev->link;
        prev->link = pres;
    }
}
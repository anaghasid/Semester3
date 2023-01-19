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
    Node *newnode=(Node*)malloc(sizeof(Node));
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

void deleteAlt(Node* head)
{
    Node* pres = head;
    Node* prev = NULL;
    Node* temp;
    if(head==NULL)
        return;
    while(pres!=NULL && pres->link!=NULL)
    {
        prev = pres;
        pres = pres->link;
        pres = pres->link;
        temp = prev->link;
        prev->link = pres;
    }
}

void destroyList(Node* head)
{
    Node* pres = head;
    Node* prev = NULL;
    while(pres!=NULL)
    {
        prev = pres;
        pres = pres->link;
        free(prev);
    }
}
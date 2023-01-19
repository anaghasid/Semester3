// implement circular linked list with insert front and delete functions
// find last element by while(cur->link!=head)
#include<stdio.h>
#include<stdlib.h>
#include"CircularSinglyHeader.h"

circ* insertFront(circ* head, int ele)
{
    circ* temp = (circ*)malloc(sizeof(circ));
    temp->data = ele;
    temp->link = NULL;
    circ* cur = head;
    if(head==NULL)      // insert first element
    {
        head = temp;
        temp->link = temp;
        return head;
    }
    else
    {
        while(cur->link!=head)      
            cur = cur->link;    // reach the last element
        temp->link = head;      
        head = temp;        
        cur->link = head;       // last element's link points to the new head
        return head;
    }
}

void displayList(circ* head)
{
    circ* cur = head;
    if(head==NULL)
    {
        printf("Invalid\n");
        return;
    }
    if(cur->link==head)
    {
        printf("%d\n",cur->data);
        return;
    }
    while(cur->link!=head)
    {
        printf("%d\t",cur->data);
        cur = cur->link;
    }
    printf("%d\t",cur->data);
    printf("\n"); 
}

circ* deleteRear(circ* head)
{
    circ* pres = head;
    circ* last = pres;
    while(pres->link!=head)
    {
        last = pres;
        pres = pres->link;
    }   
    last->link = head;
    free(pres);
    return head;
}
 
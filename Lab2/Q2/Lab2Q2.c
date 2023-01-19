#include<stdio.h>
#include<stdlib.h>
#include "DoublyLLHeader.h"

dll* insertRear(dll* head, int num)
{
    dll* temp = (dll*)malloc(sizeof(dll));
    temp->left = NULL;
    temp->right = NULL;
    temp->n = num;
    if(head==NULL)
        head = temp;
    else
    {
        dll* pres = head;
        while(pres->right!=NULL)
            pres = pres->right;
        pres->right = temp;
        temp->left = pres; 
    }
    return head;
}


dll* mergeLists(dll* head1, dll* head2,dll* merged)
{
    merged = NULL;
    dll* cur1 = head1, *cur2 = head2;
    while(cur1!=NULL && cur2!=NULL)
    {
        if(cur1->n < cur2->n)
        {
            //printf("Inserting %d\n",cur1->n);
            merged = insertRear(merged, cur1->n);
            cur1 = cur1->right;
        }
        else{
            merged = insertRear(merged, cur2->n);
            cur2 = cur2->right;
        }
        
    }
    while(cur1!=NULL)
    {
        merged = insertRear(merged,cur1->n);
        cur1 = cur1->right;
    }

    while(cur2!=NULL)
    {
        merged = insertRear(merged,cur2->n);
        cur2 = cur2->right;
    }
    return merged;
}


void displayList(dll* head)
{
    dll* present = head;
    while(present!=NULL)
    {
        printf("%d\t",present->n);
        present = present->right;
    }
    printf("\n");
}



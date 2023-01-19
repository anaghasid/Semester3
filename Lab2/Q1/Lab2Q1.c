#include<stdio.h>
#include<stdlib.h>
#include "DoublyLLHeader.h"

// doubly linked list
// circular linked list is used to scheduling CPU jobs. Can be implemented singly or doubly
// create two lists, add them and store in another list
// store each digit in different nodes. First node being MSB. Pass carry to prev.

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
        while(pres->right!=NULL && pres->n < num)
        {         
            pres = pres->right;
        }
        
        if(pres==head && pres->n > num)
        {
            temp->left = pres;
            pres->right = temp;
        }
        temp->left = pres->left;
        pres->left = temp;
        temp->right = pres;
    }
    return head;
}

int searchInfo(dll* head,int ele)
{
    dll* cur = head;
    int i=0;
    while(cur->right != NULL)
    {
        if(cur->n == ele)
        {
            printf("Yes!\n");
            break;
        }
        cur = cur->right;
        i++;
    }
    return i;
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



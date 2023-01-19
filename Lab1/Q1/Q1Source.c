#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include "Q1Header.h"

poly* createList(poly* head)
{
    head = NULL;
    return head;
}

poly* getList(poly* head,int x, int y,int coeff)
{
    poly *temp = (poly*)malloc(sizeof(poly));
    temp->px = x;
    temp->py = y;
    temp->coeff = coeff;
    temp->next = NULL;
    poly* pres=head;
    if(head==NULL)
    {
        head = temp;
        return head;
    }
    else
    {
    while(pres->next!=NULL)
    {
        pres = pres->next;
    }
    pres->next = temp;  // insertion at rear end
    }
    return head;
}

void displayList(poly* head)
{
    poly* pres=head;
    printf("Terms in the final answer are:\n");
    while(pres!=NULL)
    {
        printf("%d x^%d y^%d \n",pres->coeff,pres->px,pres->py);
        pres = pres->next;
    }  
    printf("----\n"); 
}

/*poly* addPoly(poly* head1, poly* head2, poly* sum)
{
    poly* pres1 = head1;
    while(pres1!=NULL)
    {
        poly* pres2 = head2;
        while(pres2!=NULL)
        {
            if(pres1->px == pres2->px && pres1->py==pres2->py)
            {
                printf("Equal\n");
                printf("sum points to %p\n",sum);
                poly* temp;;
                temp->coeff = pres1->coeff + pres2->coeff;
                temp->px = pres2->px;
                temp->py = pres1->py;
                temp->next = NULL;
                pres1->flag = 1;
                pres2->flag = 1;
                if(sum==NULL)
                {
                    printf("Adding to sum head\n");
                    sum = temp;
                }
                else
                {
                    poly* pres=sum;
                    while(pres->next!=NULL)
                    {
                        pres = pres->next;
                    }
                    pres->next = temp;
                }
            }
            pres2 = pres2->next;
        }
        pres1 = pres1->next;
    }
    
    return sum;
}*/

poly* addPoly(poly* head1, poly* head2)
{
    if(head1 == NULL)
        return head2;
    else if(head2==NULL)
        return head1;
    else
    {
    poly* pres1 = head1;
    poly* last1 = pres1;
    while(pres1!=NULL)
    {
        poly* pres2 = head2;
        while(pres2!=NULL)
        {
            if(pres1->px == pres2->px && pres1->py==pres2->py)
            {
                pres1->coeff += pres2->coeff;
                pres2->flag = 1;    // to see if it is a unique term
            }
            pres2 = pres2->next;
        }
        last1 = pres1;
        pres1 = pres1->next;
    }

    poly* pres2 = head2;
    while(pres2!=NULL)
    {
        if(pres2->flag!=1)
        {
            poly* temp = (poly*)malloc(sizeof(poly));
            temp->coeff = pres2->coeff;
            temp->px = pres2->px;
            temp->py = pres2->py;
            temp->next = NULL;
            last1->next = temp;
            last1 = last1->next;
        }
        pres2 = pres2->next;
    }
    }
    return head1;
}

void freeList(poly *head)
{
    poly* present = head;
    poly* prev = NULL;
    while(present!=NULL)
    {
        prev = present;
        present=present->next;
        free(prev);
    }
}
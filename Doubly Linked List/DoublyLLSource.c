#include<stdio.h>
#include<stdlib.h>
#include "DoublyLLHeader.h"

// doubly linked list
// circular linked list is used to scheduling CPU jobs. Can be implemented singly or doubly
// create two lists, add them and store in another list
// store each digit in different nodes. First node being MSB. Pass carry to prev.

dll* insertFront(dll* head, int num)
{
    int n=num;
    if(num==0)
    {
        dll* temp = (dll*)malloc(sizeof(dll));
        temp->left = NULL;
        temp->right = NULL;
        temp->n = 0;
        if(head == NULL)
        {
            head = temp;
            //return head;
        }
        else
        {
            head->left = temp;
            temp->right = head;
            head = temp;
        }

    }
    while(num)
    {
        dll* temp = (dll*)malloc(sizeof(dll));
        temp->left = NULL;
        temp->right = NULL;
        temp->n = num%10;
        if(head == NULL)
        {
            head = temp;
            //return head;
        }
        else
        {
            head->left = temp;
            temp->right = head;
            head = temp;
        }
        num = num/10;    
    }
    return head;
}

void displayList(dll* head)
{
    dll* present = head;
    while(present!=NULL)
    {
        printf("%d",present->n);
        present = present->right;
    }
    printf("\n");
}

dll* addNumbers(dll* head1, dll* head2)
{
    dll *cur1 = head1, *cur2 = head2;
    dll *sum = (dll*)malloc(sizeof(dll)); 
    sum = NULL;
    int carry = 0;
    int sumdigit;
    while(cur1->right != NULL) // to reach to last digit
        cur1 = cur1->right;
    
    while(cur2->right != NULL)
        cur2 = cur2->right;
    
    while(cur1!=NULL && cur2!=NULL)
    {
        sumdigit = cur1->n + cur2->n + carry;
        // if(sumdigit>9)
        // {    
            carry = sumdigit/10;
            sumdigit = sumdigit%10; 
        // }
        // else
        //     carry = 0;
        sum = insertFront(sum,sumdigit);
        cur1 = cur1->left;
        cur2 = cur2->left;
    }

    while(cur1!=NULL)   // if cur2 has reached its end.
    {
        sumdigit = cur1->n + carry;
        if(sumdigit>9)
        {
            carry = sumdigit/10;
            sumdigit = sumdigit%10; 
        }
        else
            carry = 0;
        sum= insertFront(sum,sumdigit);
        cur1 = cur1->left;
    }

    while(cur2!=NULL)
    {
        sumdigit = cur2->n + carry;
        if(sumdigit>9)
        {
            carry = sumdigit/10;
            sumdigit = sumdigit%10; 
        } 
        sum = insertFront(sum,sumdigit);
        cur2 = cur2->left;
    }
    
    if(cur1==NULL && cur2==NULL)
    {
        if(carry!=0)
        {
            sum = insertFront(sum,carry);
        }
    }
    return sum;
}
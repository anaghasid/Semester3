// kill ALTERNATE PEOPLE until only one survivor.
// All even nodes eliminated
/*
n   survivor
1   1
----
2   1
3   3
---
4   1
5   3
6   5
7   7
---
8   1
9   3
10  5
11  7
12  9
13  11
14  13
15  15
--- 
Whenever n=power of 2, survivor is 1
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct scircular
{
    int data;
    struct scircular* link;
};
typedef struct scircular circ;


circ* insertRear(circ* head, int ele)
{
    circ* temp = (circ*)malloc(sizeof(circ));
    temp->data = ele;
    temp->link = NULL;
    circ* cur = (circ*)malloc(sizeof(circ));
    cur = head;
    if(head==NULL)
    {
        head = temp;
        temp->link = head;
        return head;
    }
    while(cur->link!=head)
    {
        cur = cur->link;
    }

    cur->link = temp;
    temp->link = head;
    return head;
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
 
circ* deletePosition(circ* head, int pos)
{
    // no condition of deleting last element
    circ* pres = head;
    int res;
    circ* prev = NULL;
    if(head->data==pos)
    {
        if(head->link==head)    // if only one node in the circular LL
        {
            printf("Empty list\n");
            return head;
        }
        prev = head;
        while(prev->link!=head)
            prev = prev->link;
        head = head->link;
        prev->link = head;
        // free(pres);
    }
    else
    {
    prev = pres;
    pres = pres->link;
    while(pres!=head)
    {
        if(pres->data==pos)
        {
            res = pres->data;
            prev->link = pres->link;
            // free(pres);
            return head;
        }
        prev = pres;
        pres = pres->link;
    }
    }
    return head;
    
}

int isLone(circ* head)
{
    // checking if only one surivivor is remaining
    if(head->link==head)
    {
        return 1;
    }
    return 0;
}

circ* deleteAlt(circ* head)
{
    circ* pres = head->link;
    circ* killer = head;
    circ* next = NULL;
    while(!isLone(head))
    {
        next = pres;
        killer = pres->link;
        pres = pres->link->link;         
        head = deletePosition(head,next->data);
        // displayList(head); 
    }
    return head;
}


int main()
{
    circ* jos;
    jos = (circ*)malloc(sizeof(circ));
    jos = NULL;
    int choice, ele;
    int num;
    printf("Enter the number of soldiers\n");
    scanf("%d",&num);
    fflush(stdin);
    for(int i=0;i<num;i++)
    {
        jos = insertRear(jos, i+1);
    }
    // displayList(jos);
    jos = deleteAlt(jos);
    printf("Safe position is %d\n\n",jos->data);
    return 0;
}


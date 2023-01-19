#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct poly
{
    int coeff;
    int power;
    struct poly* link;
}polynode;

polynode* insertRear(polynode* head, int coeff, int power)
{
    polynode *newnode=NULL;
    polynode *cur; //creating a new node so head points to that and that again points to first ele
    newnode = (polynode*)malloc(sizeof(polynode));
    newnode->coeff = coeff;
    newnode->power = power;
    newnode->link=NULL;

    cur=head;
    if(head==NULL)
    {
        head = newnode;
    }
    else
    {
        while(cur->link!=NULL)
            cur=cur->link;
        cur->link=newnode;
    }
    return head;
}

void display(polynode* head)
{
    if(head==NULL)
    {
        printf("Empty list\n");
        return;
    }
    polynode* cur = head;
    while(cur!=NULL)
    {
        printf("%dX^%d + ",cur->coeff,cur->power);
        cur = cur->link;
    }
}

int findDerivative(polynode* head, int x, int n)
{
    if(head==NULL)
    {
        printf("Empty list\n");
        return 0;
    }
    polynode* cur = head;
    int sum = 0;
    int po;
    while(cur!=NULL)
    {
        po = (cur->power) - 1;
        sum += (cur->coeff)*(cur->power)*(pow(x,po));
        cur = cur->link;
    }
    return sum;
}

int main()
{
    polynode* head = NULL;
    head = insertRear(head, 2,2);
    head = insertRear(head,5,1);
    head = insertRear(head,4,0);   // 2X^2 + 5X + 4
    display(head);
    int ans = findDerivative(head,2,2);
    printf("\nAnswer is %d",ans);
    return 0;
}
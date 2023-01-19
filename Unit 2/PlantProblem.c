// plants dying if right has more pesticide than left
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct plant
{
    int pest;
    int id;
};
typedef struct plant plant;

struct node
{
    plant ele;
    struct node* link;
};
typedef struct node node;

node* insert(node* head,int pes, int num)
{
    node* new = (node*)malloc(sizeof(node));
    new->ele.pest= pes;
    new->ele.id = num;
    new->link = NULL;
    if(head==NULL)
    {
        head = new;
        return head;
    }
    node* pres = head;
    while(pres->link!=NULL)
    {
        pres = pres->link;
    }
    pres->link = new;
    return head;
}

int isSorted(node* head)
{
    node *pres = head;
    while(pres->link!=NULL)
    {
        if(pres->ele.pest < (pres->link)->ele.pest)
            return 1;
        pres = pres->link;
    }
    return 0;
}

node* deleteElement(node* head, node* pres)
{
    // no condition to delete if only one element is present.
    // no condition of changing head
    node* prev = head;
    node* i = NULL;
    while(prev->link!=NULL)
    {
        i = prev->link;
        if(i==pres)
        {
            prev->link = i->link;
            free(i);
            return head;
        }
        prev = prev->link;
    }
    return head;
}

/*
node* deleteUnwanted(node* head)
{
    node* prev = head;
    node* pres = NULL;
    while(prev!=NULL && prev->link!=NULL)
    {
        pres = prev->link;
        if(pres->ele.pest > prev->ele.pest)
        {
            head = deleteElement(head,pres);
        }
        // if(prev->link==NULL)
        //    return head;
        prev = prev->link->link;
    }
    return head;
}
*/

void deleteUnwanted(node* head)
{
    node* prev = head;
    node* pres = NULL;
    while(prev!=NULL && prev->link!=NULL)
    {
        pres = prev->link;
        if(prev->ele.pest < pres->ele.pest)
        {
            deleteUnwanted(pres);
            deleteElement(head,pres);
        }
        else
            prev = prev->link;
    }
    return;

}

void display(node* head)
{
    if(head == NULL)
    {
        printf("Empty list\n\n");
    }
    node* pres = head;
    while(pres!=NULL)
    {
        printf("(%d,%d)\t",pres->ele.pest,pres->ele.id);
        pres = pres->link;
    }
    printf("\n");

}

int main()
{
    node n;
    int pesticide, num;
    node* head = (node*)malloc(sizeof(node));
    head = NULL;
    printf("Enter elements and end with -1\n");
    scanf("%d",&pesticide);
    scanf("%d",&num);
    while(pesticide!=-1 && num!=-1)
    {   
        head = insert(head,pesticide,num); // at rear position
        scanf("%d",&pesticide);
        scanf("%d",&num);
    }
    display(head);
    int i = 1;
    // while(isSorted(head))
    // {
        deleteUnwanted(head);
        display(head);
        i++;
    // }
    return 0;
}
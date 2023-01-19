#include<stdio.h>
#include<stdlib.h>
#include "List1Header.h"

void createList(List* mylist, int listsize)
{
    mylist->arr = (int*)malloc(listsize*sizeof(int));
    mylist->arrsize = listsize;
    mylist->noe = 0;
}

void insert_ele(List* mylist, int ele, int pos)
{
    if(pos>mylist->arrsize || pos<0)
        printf("Invalid position\n");
    else if(mylist->noe>=(mylist->arrsize))
        printf("List is full\n");
    else
    {
        if(pos>=mylist->noe)
        {
            mylist->arr[mylist->noe] = ele;
            mylist->noe = mylist->noe + 1;
        }
        else
        {
            for(int i=(mylist->noe)-1;i>=pos;i--)
            {
                mylist->arr[i+1] = mylist->arr[i];
            }
            mylist->arr[pos] = ele;
            mylist->noe = mylist->noe + 1;
        }

    }
}

void display(List* lptr)
{
    for(int i=0;i<lptr->noe;i++)
        printf("%d\t",lptr->arr[i]);
    printf("\n");
}

void delete_ele(List* mylist, int pos)
{
    if(pos<0 || pos>mylist->noe)
    {
        printf("Invalid\n");
    }
    else{
    printf("Deleted %d\n",mylist->arr[pos]);
    for(int i=pos;i<(mylist->noe)-1;i++)
    {
        mylist->arr[i] = mylist->arr[i+1]; 
    }
    mylist->noe--;
    }
}

void search(List* mylist, int ele)
{
    int pos=-1;
    printf("ele = %d",ele);
    for(int i=0;i<mylist->noe;i++)
    {
        if(mylist->arr[i]==ele)
            pos = i;
    }
    if(pos>-1)
        printf("Element found at position %d\n",pos);
    else
    printf("Not found pos = %d\n",pos);
}


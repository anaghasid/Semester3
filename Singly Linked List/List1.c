#include<stdio.h>
#include<stdlib.h>
#include "List1Header.h"

int main()
{
    List mylist;
    int listsize, ele, pos;
    int choice, element;
    while(1)
    {
        printf("1.Create list\n2.Insert element\n3.Delete element\n4.Display\5.Search\n6.Exit\n");
        scanf("%d",&choice);
        fflush(stdin);
        switch(choice)
        {
            case 1: printf("Enter list size\n");
            scanf("%d",&listsize);
            createList(&mylist, listsize);
            break;
            case 2: printf("Enter element and position\n");
            scanf("%d",&ele);
            scanf("%d",&pos);
            fflush(stdin);
            insert_ele(&mylist,ele, pos);
            display(&mylist);
            break; 
            case 3: printf("Enter position to delete\n");
            scanf("%d",&pos);
            fflush(stdin);
            delete_ele(&mylist,pos);
            display(&mylist);
            break;
            case 4: display(&mylist);
            break;
            case 5: printf("Enter element to be searched\n");
            scanf("%d",&element);
            fflush(stdin);
            printf("ele = %d",element);
            search(&mylist, element);
        }
    }    
}


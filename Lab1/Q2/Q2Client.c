#include<stdio.h>
#include<conio.h>
#include"ll1.h"

int main()
{
    Node* head;
    int choice,ele,pos;
    head = createlist(head);
    do
    {
        printf("\nMenu\n1. Insert Front\n2. Display\n3. Delete alternative\n4.Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: printf("Enter the element\n");
        scanf("%d",&ele);
        head = InsertFront(head,ele);
            break;
        case 2: Display(head);
        break;
        case 3: printf("After deleting alternative elements:\n");
        deleteAlt(head);
        Display(head);
        break;
        default:
            break;
        }
    } while (choice<5 && choice>0);
    destroyList(head);
    return 0;


}
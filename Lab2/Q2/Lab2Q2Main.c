#include<stdio.h>
#include<stdlib.h>
#include "DoublyLLHeader.h"

int main()
{
    dll *head1 = NULL, *head2 = NULL, *merged = NULL;
    int choice, ele, pos, element;
    do
    {
        printf("\nMenu\n1.Insert to first list \n2. Insert to second list\n3. Merged lists\n4. Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: printf("Enter the element\n");
        scanf("%d",&ele);
        head1 = insertRear(head1,ele);
        break;

        case 2: printf("Enter the element\n");
        scanf("%d",&ele);
        head2 = insertRear(head2,ele);
        break;

        case 3: merged = mergeLists(head1,head2,merged);
        printf("The merged list is\n");
        displayList(merged);
        break;
        default:
            break;
        }
    } while (choice<4 && choice>0);
    return 0;
    return 0;

}
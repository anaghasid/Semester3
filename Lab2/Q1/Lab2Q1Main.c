#include<stdio.h>
#include<stdlib.h>
#include "DoublyLLHeader.h"

int main()
{
    int num1,num2;
    dll* head = NULL;
    int choice, ele, pos, element;
    do
    {
        printf("\nMenu\n1.Insert\n2. Search for number\n3. Display list\n4.. Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: printf("Enter the element\n");
        scanf("%d",&ele);
        head = insertRear(head,ele);
        break;
        case 2: printf("Enter the element to search\n");
        scanf("%d",&element);
        pos = searchInfo(head,element);
        printf("Element found at position %d\n",pos);
        break;
        case 3: displayList(head);
        break;
        default:
            break;
        }
    } while (choice<4 && choice>0);
    return 0;

}
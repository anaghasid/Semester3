#include<stdio.h>
#include<stdlib.h>
#include "CircularSinglyHeader.h"

int main()
{
    int num, choice;
    circ* p1 = NULL;
    printf("Insert(1) or delete(2) or exit?\n");
    scanf("%d",&choice);
    while(choice<3)
    {
        switch(choice)
        {
        case 1: printf("Enter number\n");
        scanf("%d",&num);
        p1 = insertFront(p1,num);
        displayList(p1);
        break;
        case 2: p1 = deleteRear(p1);
        displayList(p1);
        break;
        }
        printf("Insert(1) or delete(2) or exit?\n");
        scanf("%d",&choice);
    } 
    

    return 0;
}
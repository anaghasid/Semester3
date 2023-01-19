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
        printf("\nMenu\n1.Insert Front\n2. Insert Rear\n3. Insert at middle\n4. Display\n5. Delete front\n6. Delete alternative\n7.Exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: printf("Enter the element\n");
        scanf("%d",&ele);
        head = InsertFront(head,ele);
            break;
        case 2: printf("Enter the element\n");
        scanf("%d",&ele);
        head = InsertRear(head,ele);
        break;
        case 3: printf("Insert position and element\n");
        scanf("%d",&pos);
        scanf("%d",&ele);
        head = Insertatpos(head,ele,pos);
        break;
        case 4: Display(head);
        break;
        case 5: head = deleteFront(head);
        break;
        case 6: printf("Deleting alternative elements:\n");
        deleteAlt(head);
        Display(head);
        break;
        default:
            break;
        }
    } while (choice<7);

    
    return 0;


}
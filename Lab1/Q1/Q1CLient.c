#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include"Q1Header.h"
 
 int main()
 {
    poly* head1;
    poly* head2;
    poly* sum;
    int n1,n2;
    int c,x,y;
    head1 = createList(head1);
    head2 = createList(head2);
    printf("Enter the number of terms in the first polynomial\n");
    scanf("%d",&n1);
    for(int i=0;i<n1;i++)
    {
        printf("Enter coefficient, power of x, power of y\n");
        scanf("%d",&c);
        scanf("%d",&x);
        scanf("%d",&y);
        head1 = getList(head1,x,y,c);
    }
    printf("Enter the number of terms in the second polynomial\n");
    scanf("%d",&n2);
    for(int i=0;i<n2;i++)
    {
        printf("Enter coefficient, power of x, power of y\n");
        scanf("%d",&c);
        scanf("%d",&x);
        scanf("%d",&y);
        head2 = getList(head2,x,y,c);
    }

    head1 = addPoly(head1,head2);   // storing the resulting polynomial in head1
    displayList(head1);
    freeList(head1);
    freeList(head2);
    return 0;
 }

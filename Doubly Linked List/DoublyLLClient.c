#include<stdio.h>
#include<stdlib.h>
#include "DoublyLLHeader.h"

int main()
{
    int num1,num2;
    dll* p1 = NULL, *p2 = NULL, *sum = NULL;
    printf("Enter number 1 and number 2\n");
    scanf("%d",&num1);
    scanf("%d",&num2);
    p1 = insertFront(p1,num1);
    p2 = insertFront(p2,num2);
    //displayList(p1);
    sum = addNumbers(p1,p2);
    displayList(sum);
    return 0;

}
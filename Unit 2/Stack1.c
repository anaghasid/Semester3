// STACKS
// last in first out
/*operations: push (like insertFront),
pop (remove last element inserted to stack, like deleteFront),
peep (look at last inserted element),
init (initialize stack. Top = -1),
isEmpty (stack underflow),
isFull (stack overflow),
display.
Top points to the last element inserted.
Can be implemented as array or linked list*/

// ARRAY IMPLEMENTATION
#include <stdio.h>
#include <stdlib.h>
#define MAX 20

struct stack
{
    int *stackele;
    int top;
};
typedef struct stack Stack;

int isEmptyStack(Stack *s)
{
    if (s->top == -1)
        return 1;
    return 0;
}

void initStack(Stack *s, int size)
{
    s->stackele = (int *)malloc(size * sizeof(int));
    s->top = -1;
}

int isFullStack(Stack *s)
{
    if (s->top == MAX - 1)
        return 1;
    return 0;
}

void push(Stack *s, int ele)
{
    if (isFullStack(s) == 1)
        printf("Overflow, cannot push\n");
    else
    {
        s->top++;
        s->stackele[s->top] = ele;
    }
}

void pop(Stack *s)
{
    if (isEmptyStack(s) == 1)
        printf("No elements, cannot pop\n");
    else
    {
        s->top--;
    }
}

void displayStack(Stack *s)
{
    for (int i = 0; i <= s->top; i++)
    {
        printf("%d\t", s->stackele[i]);
    }
    printf("\n");
}

void peekStack(Stack *s)
{
    if (isEmptyStack(s) == 1)
        printf("Empty stack\n");
    else
    {
        printf("The last element is %d\n", s->stackele[s->top]);
    }
}

int main()
{
    int stacksize, choice, ele;
    Stack s;
    stacksize = MAX;
    initStack(&s, stacksize);
    // printf("\nEnter the stack size: ");
    // scanf("%d",&stacksize);
    printf("\nMenu\n");
    while (1)
    {
        printf("1. Push\n2. Pop\n3. Display \n4. Peek\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to push\n");
            scanf("%d", &ele);
            push(&s, ele);
            break;
        case 2:
            pop(&s);
            break;
        case 3:
            displayStack(&s);
            break;
        case 4:
            peekStack(&s);
            break;
        default:
            exit(0);
        }
        printf("\n");
    }
}
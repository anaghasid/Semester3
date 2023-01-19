// Brackets in opening and closing order. Check if in order
// INCOMPLETE PROGRAM. HANDLE BRACKETS!
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20

struct stack
{
    char *stackele;
    int top;
};
typedef struct stack Stack;

int isEmptyStack(Stack* s)
{
    if(s->top==-1)
        return 1;
    return 0;
}

void initStack(Stack* s,int size)
{
    s->stackele = (char*)malloc(size*sizeof(char));
    s->top = -1;
}


int isFullStack(Stack* s)
{
    if(s->top == MAX-1)
        return 1;
    return 0;
}

void push(Stack* s, char ele)
{
    if(isFullStack(s)==1)
        printf("Overflow, cannot push\n");
    else
    {
        s->top++;
        s->stackele[s->top] = ele;
    }
}

void pop(Stack *s)
{
    if(isEmptyStack(s)==1)
        printf("No elements, cannot pop\n");
    else{
        s->top--;
    }
}


int main()
{
    Stack a;
    int n;
    char ch;
    printf("Enter the string: ");
    initStack(&a,20);
    while(ch!='\n')  
    {
        scanf("%c",&ch);
        if(ch=='('|| ch=='[' || ch=='{')
        {
            push(&a,ch);
        }
        if(ch==')')
        {
            if(isEmptyStack(&a)==1)     
            // to handle the condition where the first one to enter stack is a closing bracket
            {
                push(&a,ch);
                break;
            }

            if(a.stackele[a.top]=='(')  
            // to check if last opening element corresponds to this closing bracket
            {
            pop(&a);
            }
        }
        if(ch==']')
        {
            if(isEmptyStack(&a)==1)
            {
                push(&a,ch);
                break;
            }
            if(a.stackele[a.top]=='[')
            pop(&a);
        }
        if(ch=='}')
        {
            if(isEmptyStack(&a)==1)     
            {
                push(&a,ch);
                break;
            }
            if(a.stackele[a.top]=='{')
            pop(&a);
        }
    }
    if(isEmptyStack(&a)==1)
    {
        printf("In correct order\n");
    }
    else
        printf("Wrong order\n");
}
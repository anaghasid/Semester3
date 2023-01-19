#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define MAX 20

struct stack
{
    int *stackele;
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
    s->stackele = (int*)malloc(size*sizeof(int));
    s->top = -1;
}


int isFullStack(Stack* s)
{
    if(s->top == MAX-1)
        return 1;
    return 0;
}

void push(Stack* s, int ele)
{
    if(isFullStack(s)==1)
        printf("Overflow, cannot push\n");
    else
    {
        s->top++;
        s->stackele[s->top] = ele;
    }
}

int operate(int a, int b, char op)
{
    int res;
    if(op=='+')
        res = a+b;
    if(op=='-')
        res = a-b;
    if(op=='*')
        res = a*b;
    if(op=='/')
        res = a/b;
    if(op=='^')
        res=pow(a,b);
    return res;
}


void pop(Stack *s)
{
    if(isEmptyStack(s)==1)
        printf("No elements, cannot pop\n");
    else{
        s->top--;
    }
}

void displayStack(Stack* s)
{
    for(int i=0;i<=s->top;i++)
    {
        printf("%d\t",s->stackele[i]);
    }
    printf("\n");
}


int main()
{
    Stack a;
    int n;
    char ch[30];
    initStack(&a,30);
    printf("Enter the string: ");
    scanf("%c",&ch[0]);
    int i=0;
    while(ch[i]!='\n')
    {
        if(isdigit(ch[i]))
        {
            int num = atoi(&ch[i]);     // problem fixed: atoi took address and therefore the next array elements too. 
            push(&a,num);
        }
        else if(ch[i]=='+' || ch[i]=='-' ||ch[i]=='*' ||ch[i]=='/' ||ch[i]=='^')
        {
            displayStack(&a);
            if(isEmptyStack)   // not empty
            {
                int opand1 = a.stackele[a.top];
                pop(&a);
                int opand2 = a.stackele[a.top];
                pop(&a);
                int t = operate(opand2,opand1,ch[i]);
                push(&a,t);

            }
        }
        else
        {
            printf("Invalid expression\n");
        }
        i++;
        scanf("%c",&ch[i]);
    }
    printf("Result is %d\n",a.stackele[a.top]);
    return 0;
}
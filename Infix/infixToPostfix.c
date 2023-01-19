/* Postfix helpful because variables can be scanned at once and then operated on
Syntax: operand1 operand2 operator
a+b ->> ab+
a+b-c ->> ab+c-
a+b*c ->> abc*+
a+b*c/d ->> abc*d/+     (because a[(bc*)d/]+)
a*b+c ->> abc+*
Find the first operator and operate it between the previous two variables. 
Store the result in some t1, then encounter the next operator and operate between t1 and the other operand.

token, stack, postfix
Read token, insert all operands to postfix.
If stack is empty, push operator to stack.
If stack isnot empty, if the incoming operator precedence is higher than top stack element, push it to stack.
If not, put the top element to postfix expression and check incoming operator again
If they are equal precedence, check for associativity

*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX 30


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

int precedence(char ele)
{
    int prec;
    if(ele=='+' || ele=='-')
        prec = 1;
    else if(ele=='*' || ele=='/')
        prec=2;
    else if(ele=='^')
        prec=3;
    else if(ele=='('|| ele==')')
        prec=4;
    else
        prec=0;
    return prec;
}

void pop(Stack *s)
{
    if(isEmptyStack(s)==1)
        printf("No elements, cannot pop\n");
    else
    {
        s->top--;
    }
}

void displayStack(Stack* s)
{
    for(int i=0;i<=s->top;i++)
    {
        printf("%c",s->stackele[i]);
    }
    printf("\n");
}


int main()
{
    Stack s, postfix;
    char c;
    char st[100];
    int pres;
    initStack(&s,30);
    initStack(&postfix,30);
    printf("Enter the infix expression: ");
    gets(st);
    int i=0;
    while(st[i]!='\0')
    {
        c=st[i];
        if(isalpha(c)!=0)
        {
            printf("%c going to postfix:\n",c);
            push(&postfix,c);
            //displayStack(&postfix);
            
        }
        else
        {
             if(precedence(c)!=0 && precedence(c)!=4)
            {
            pres = precedence(c);
            if(isEmptyStack(&s))
            {
                push(&s,c);
            }
            
            else
            {
                pres = precedence(c);
                int prestop = precedence(s.stackele[s.top]);
                if(pres>prestop)
                {
                    push(&s,c);
                }
                else if(pres<prestop)
                {
                    push(&postfix,s.stackele[s.top]);
                    pop(&s);
                    push(&s,c);
                }
                else
                {
                    if(c=='^')
                        push(&s,c);
                    else
                    {
                    push(&postfix,s.stackele[s.top]);
                    pop(&s);
                    push(&s,c);
                    }
                }
            }
            }
            if(precedence(c)==4)
            {
                if(c=='(')
            }
        }
        displayStack(&postfix);
        i++;       
        
    }
    while(isEmptyStack(&s)==0)
    {
        push(&postfix,s.stackele[s.top]);
        pop(&s);
    }
    displayStack(&postfix);
    return 0;
}
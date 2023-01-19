/*
a+b-->ab+
a+b-c-->ab+c-
a+b*c-->abc*+
a+b*c/d-->  abc*d/+
a*(b+c)-->   abc+*
FIND THE OPERATOR AND COMPUTE THE OPERATOR TO PREVIOUS 2 OPERENDS AND AGAIN SEARCH FOR THE NEXT OPERATOR AND COMPUTE IT WITH PREVIOUS RESULT AND SO ON..

a+b*c-d/e*f
token   stack    postfix            token-operand-copy to postfix array
a          +            a              token-operator-if stack is empty push it to stack
+                       b                             -if stack is not empty check the precidence of the operator and if the incoming operator precedence 
b                        ab                                 is higher than that of the top element push it to the stack
                                                    -if the precedence of incoming operator< precedence at top of the stack
*   (comapre the precidence with the top of the stack)   append to the top tof the stack if precidence is high pop the stack top element and copy to postfix     
c                         abc                           -incoming operator precendence==precedence of top pop this copy to postfix
-       
when there is an operend directly place it to postfix expression

*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct stack
{
    char *stackele;
    int top;
};
typedef struct stack stack;
void initstack(stack *s,int stacksize)
{
    s->stackele=(char*)malloc(stacksize*sizeof(char));
    s->top=-1;

}
void push(stack *s,char ele,int stacksize)
{
    if(isFullStack(s,stacksize)==1)
    {
        printf("stack overflow cant push:(\n");
    }
    else
    {
        s->top++;
        s->stackele[s->top]=ele;  
    }
}
void pop(stack *s)
{
    if(isEmptyStack(s))
        printf("stack underflow cant delete:(\n");
    else
    {
        s->top--;
    }
}
int isFullStack(stack *s,int stacksize)
{
    if(s->top+1==stacksize)
    {
        return 1;
    }
    return 0;
}
int isEmptyStack(stack *s)
{
    if(s->top==-1)
    {
        return 1;
    }
    return 0;
}
void display(stack *s)
{
    for(int i=0;i<=s->top;i++)
    {
        printf("%c ",s->stackele[i]);
    }
    printf("\n");
}
int precedence(char ele)
{
    if(ele=='+' || ele=='-')
    {
        return 1;
    }
    else
    if(ele=='*' || ele=='/')
    {
        return 2;
    }
    else
    if(ele=='^')
    return 3;
    else
    if(ele=='(' || ele==')')
    return 4;
}
int main()
{
    stack s,postfix;
    char c;
    int size;
    printf("enter the size:");
    scanf("%d",&size);
    fflush(stdin);
    initstack(&s,size);
    initstack(&postfix,size);
    for(int i=0;i<size;i++)
    {
        scanf("%c",&c);
        //printf("ele:%c\n",c);
        if(isalpha(c))
        {
            push(&postfix,c,size);
        }
        else
        {
            if(isEmptyStack(&s))
            {
                push(&s,c,size);
                //printf("stack:");
                //display(&s);
                //printf("postfix:");
                //display(&postfix);
            }
            else
            {
                if(precedence(s.stackele[s.top])!=4)
                {
                if(precedence(c)>precedence(s.stackele[s.top]) && precedence(c)!=4)
                    push(&s,c,size);
                else
                if(precedence(c)<precedence(s.stackele[s.top] && precedence(c)!=4))
                {
                    
                    while(precedence(c)<=precedence(s.stackele[s.top]) && precedence(c)!=4)
                    {
                        if(isEmptyStack(&s)==0)
                        {
                        push(&postfix,s.stackele[s.top],size);
                        pop(&s);
                        }
                    }
                
                    push(&s,c,size);
                }
                else
                {
                    if(precedence(c)==4 && c=='(')
                        {push(&s,c,size);
                        //printf("function:");
                        //display(&s);
                        }
                    else
                    if(precedence(c)==4 && c==')')
                    {
                        //printf("in:");
                        //display(&s);
                        //printf("brak:");
                        //display(&postfix);
                        while(s.stackele[s.top]!='(')
                        {
                            
                            //display(&s);
                            push(&postfix,s.stackele[s.top],size);
                            pop(&s);
                        }
                        pop(&s);
                    }
                    else
                    if(c=='^')
                        push(&s,c,size);
                        
                    else
                    {
                        push(&postfix,s.stackele[s.top],size);
                        pop(&s);
                        push(&s,c,size);
                    }
                }
                }
                else
                {
                    push(&s,c,size);
                }
            }
                       
        }
        //printf("postfix:");
        //display(&postfix);
        //display(&s);
         
    }
       while(isEmptyStack(&s)==0)
            {
                    push(&postfix,s.stackele[s.top],size);
                    pop(&s);
            }
    display(&postfix);
    return 0;
}

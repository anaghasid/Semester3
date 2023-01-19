#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack{
    char *stackelements;
    int capacity;
    int top;
};
typedef struct stack Stack;
void init_stack(Stack *S,int len){
    S->stackelements=(char *)malloc(len *sizeof(char));
    S->top=-1;
    S->capacity=len;
}

int isOperand(char e){
    if((e>='a' && e<='z') || (e>='A' && e<='Z'))
        return 1;
    return 0;
}

int isEmptystack(Stack *S){
    if(S->top==-1)
        return 1;
    return 0;    
}
int isFullstack(Stack *S){
    if(S->top==S->capacity-1)
        return 1;
    return 0;    
}   
void push(Stack *S,char e){
    if(!isFullstack(S)){
    S->top++;
    S->stackelements[S->top]=e;
    }
    else{
        printf("\n stack overflow");
        exit(0);
    }
}
char pop(Stack *S){
    char e;
    if(!isEmptystack(S)){
        e=S->stackelements[S->top];
        S->top--;
        return 0;
    }
    return '\0';
}
char peek(Stack *S){
    if(!isEmptystack(S))
    return S->stackelements[S->top];
    return '\0';
}
int prec(char c){
    switch(c){
        case '+':
        case '-':return 1;
        break;
        case '*':
        case '/':return 2;
        break;
        case '^':return 3;
        break;
        default:printf("\n invalid operator");
                exit(0);
    }
}
void infixtopostfix(char *expression){
    Stack S;
    int k=0;
    char *postfixexpression;
    int len=strlen(expression);
    postfixexpression=(char *)malloc(len *sizeof(char));
    init_stack(&S,len);
    for(int i=0;i<len;i++){
        if(isOperand(expression[i]))
        {
            postfixexpression[k]=expression[i];
            k++;
        }
        else
        {
            if(expression[i]=='(')
                push(&S,expression[i]);
            else if(expression[i]==')')
            {
                    while(!isEmptystack(&S) || peek(&S)!='(')
                {
                    postfixexpression[k]=pop(&S);
                    k++;
                }    
                if(isEmptystack(&S)){
                    printf("\n Invalid infix expression");
                    exit(0);
                }
                pop(&S);
            }
            else{
                if(!isEmptystack(&S)){
                    push(&S, expression[i]);
                    continue;
                }
                if(prec(expression[i]>prec(peek(&S))))
                {  
                    push(&S, expression[i]);
                    continue;
                }    
                else if(prec(expression[i])<prec(peek(&S))){
                    while(!isEmptystack(&S) && prec(expression[i]<prec(peek(&S))))
                {
                    postfixexpression[k]=pop(&S);
                    k++;
                }

        }
    }
        }
    }
}

int main()
{
    char expression[20];
    printf("\n enter the expression:");
    scanf("%s",expression);
    infixtopostfix(expression);
    return 0;
}   
// HANDLE POWERS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

struct stack{
    char *stackelements;
    int size;
    int top;
};
typedef struct stack Stack;
void init_stack(Stack *S,int len){
    S->stackelements=(char *)malloc(len *sizeof(char));
    S->top=-1;
    S->size=len;

}
int isOperand(char e){
    if(e>='0' && e<='9')
        return 1;
    return 0;
}
int isEmptyStack(Stack *S){
    if(S->top==-1)
        return 1;
    return 0;
}
int isFullStack(Stack *S){
    if(S->top==S->size-1)
        return 1;
    return 0;
}
void push(Stack *S,char e){
    if(!isFullStack(S)){
        S->top++;
        S->stackelements[S->top]=e;
    }
    else{
        printf("\n Stack overflow");
        exit(0);
    }
}
char pop(Stack *S){
    char e;
    if(!isEmptyStack(S)){
        e=S->stackelements[S->top];
        S->top--;
        return e;
    }
    return '\0';
}
char peek(Stack *S){
    if(!isEmptyStack(S))
        return S->stackelements[S->top];
    return '\0';
}
int prec(char c){
    switch(c){
       
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default:printf("\n Invalid operator");
                exit(0);
    }
}
int isLeftAssociative(char c){
    switch(c){
        case '+':
        case '-':
        case '*':
        case '/': return 0;
        case '^': return 1;
        default: printf("\n invalid operator ");
                 exit(0);
    }
}
void display(Stack S){
    for(int i=0;i<=S.top;i++)
        printf("%c", S.stackelements[i]);
    printf("\n");
}

void revstr(char *str1)  
{   
    int i, len;
    char temp;  
    len = strlen(str1); 
    for (i = 0; i < len/2; i++)  
    {  
        temp = str1[i];  
        str1[i] = str1[len - i - 1];  
        str1[len - i - 1] = temp;  
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

char* infix_to_prefix(char *expression){
    Stack S;
    int k=0;
    char *prefixexp;
    int len=strlen(expression);
    prefixexp=(char *)malloc(len *sizeof(char));
    init_stack(&S,len);
    for(int i=0;i<len;i++){
        if(isOperand(expression[i])){
            prefixexp[k]=expression[i];
            k++;
            
            continue;
        }
        else{
            if(expression[i]==')'){
                push(&S,expression[i]);
                continue;
            }
            else if(expression[i]=='('){
                while(!isEmptyStack(&S) && peek(&S)!=')'){
                    prefixexp[k]=pop(&S);
                    k++;

                }
                
                if(isEmptyStack(&S)){
                    printf("\n Invalid Infix expression ");
                    exit(0);
                }
                pop(&S);
            
            }
            else{
                if(isEmptyStack(&S)){
                    push(&S, expression[i]);
                    continue;
                }
                if(peek(&S)==')'){
                    push(&S, expression[i]);
                    continue;
                }
                if(prec(expression[i]) > prec(peek(&S))){
                    push(&S, expression[i]);
                    continue;
                }
                else if(prec(expression[i] )< prec(peek(&S))){
                    while(!isEmptyStack(&S) && (prec(expression[i]) < prec(peek(&S)))){
                        prefixexp[k]=pop(&S);
                        k++;
                    }
                    
                }
                if(!isEmptyStack(&S) && prec(expression[i])==prec(peek(&S))){
                    if(isLeftAssociative(expression[i])){
                        while(!isEmptyStack(&S) && (prec(expression[i]) ==prec(peek(&S)))){
                         prefixexp[k]=pop(&S);
                         k++;
                        }
                        
                    }
                }
                push(&S,expression[i]);

            }
        }

    }
    while(!isEmptyStack(&S)){
        prefixexp[k]=pop(&S);
        k++;
    }
    

    prefixexp[len]='\0';
    revstr(prefixexp);
    return prefixexp;
}

int evaluate(char* ch)
{
    Stack a;
    init_stack(&a,30);
    int i=0;
    revstr(ch);
    while(ch[i]!='\0')
    {
        if(isdigit(ch[i]))
        {
            int num = ch[i]-'0';     // problem fixed: atoi took address and therefore the next array elements too. 
            push(&a,num);
        }
        else if(ch[i]=='+' || ch[i]=='-' ||ch[i]=='*' ||ch[i]=='/' ||ch[i]=='^')
        {
            
            if(isEmptyStack)   // not empty
            {
                int opand1 = a.stackelements[a.top];
                pop(&a);
                int opand2 = a.stackelements[a.top];
                pop(&a);
                int t = operate(opand1,opand2,ch[i]);
                push(&a,t);
            }
        }
        else
        {
            printf("Invalid expression\n");
        }
        i++;
    }
    return a.stackelements[a.top];
}

int main(){
    char expression[20];
    char *ans;
    int n;
    scanf("%d",&n);
    scanf("%s", expression);
    char *exp2 = expression;
    revstr(exp2);
    ans = infix_to_prefix(exp2);
    printf("%s ", ans);
    int res = evaluate(ans);
    printf("%d",res);


}
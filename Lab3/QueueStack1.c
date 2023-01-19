#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXSIZE 20


typedef struct {
    int stack1[MAXSIZE];    // stack used for enqueue
    int stack2[MAXSIZE];    // stack used for dequeue
    int top1;               // top element position of stack1
    int top2;               // top element position of stack2
}MyQueue;


int pop1(MyQueue *s)
{
    int res;
    if(s->top1==-1)
        return -1;
    else{
        res = s->stack1[s->top1];
        s->top1--;
    }
    return res;
}

int pop2(MyQueue *s)
{
    int res;
    if(s->top2==-1)
        return -1;
    else{
        res = s->stack2[s->top2];
        s->top2--;
    }
    return res;
}


void push2(MyQueue* s, int ele)
{
    if(s->top2==MAXSIZE-1)
        printf("Overflow, cannot push\n");
    else
    {
        s->top2++;
        s->stack2[s->top2] = ele;
    }
}

// push the element x to the rear end of the queue
// stack1
void enqueue(MyQueue *s, int x) 
{
    if(s->top1==MAXSIZE-1)
        printf("Overflow, cannot push\n");
    else
    {
        s->top1++;
        s->stack1[s->top1] = x;
    }   
}

// retrieve and remove the element from the front end of the queue
int dequeue(MyQueue *q) 
{
    int res;
    while(q->top1!=-1)
    {
        res = pop1(q);
        push2(q,res);
    }
    int final = pop2(q);
    while(q->top2!=-1)
    {
        res = pop2(q);
        enqueue(q,res);
    }
    return final;
}

// check if the queue is empty
bool empty(MyQueue *q) 
{
    if(q->top1==-1)
        return 1;
    return 0;
}

// retrieve the element from the front end of the queue
int peek(MyQueue *q) 
{
    if(empty(q))
        return -1;
    return q->stack1[0];
}




int validate(MyQueue *q, int pops){
    if(q->top2 != -1 || q->top1 < pops){
        return -1;
    }

    int x = pops, ele = -1;
    while(x > 0 && q->top1 != -1){
        q->stack2[++q->top2] = q->stack1[q->top1--];
        x--;
    }

    if(q->top1 != -1){
        ele = q->stack1[q->top1];
    }

    x = pops;
    while(x > 0 && q->top2 != -1){
        q->stack1[++q->top1] = q->stack2[q->top2--];
        x--;
    }

    return ele;
}


int main(){
    MyQueue q;
    q.top1 = -1;
    q.top2 = -1;

    int no_of_operations;
    scanf("%d", &no_of_operations);

    int ele, correct_ele, no_of_pops;
    char operation;

    for(int i = 0; i < no_of_operations; i++){
        scanf(" %c", &operation);
        switch (operation)
        {   
            case 'E':
                scanf("%d", &ele);
                enqueue(&q, ele);
                printf("1 ");
                break;
            
            case 'D':
                ele = dequeue(&q);
                printf("%d ", ele);
                break;
            
            case 'P':
                ele = peek(&q);
                printf("%d ", ele);
                break;

            case 'V':
                scanf("%d", &no_of_pops);
                printf("%d ", validate(&q, no_of_pops));
                break;
        }
    }

    return 0;
}
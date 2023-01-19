#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXSIZE 20


typedef struct {
    int stack1[MAXSIZE];    // stack used for enqueue
    int stack2[MAXSIZE];    // stack used for dequeue
    int top1;               // top element position of stack1
    int top2;               // top element position of stack2
} MyQueue;


// push the element x to the rear end of the queue
void enqueue(MyQueue *q, int x) {
    if (q->top1 == MAXSIZE - 1)
    {
        printf("overflow");
        // exit(1);
    }
    q->stack1[q->top1++] = x;
}


// retrieve and remove the element from the front end of the queue
int dequeue(MyQueue *q) {
        if (q->top1 == -1)
    {
        return -1;
    }
    while (q->top1 != -1)
    {
        q->stack2[++q->top2] = q->stack1[q->top1--];
    }
    int ele = q->stack1[q->top1--];
    while (q->top2 != -1)
    {
        q->stack1[++q->top1] = q->stack2[q->top2--];
    }
    return ele;
    
}


// retrieve the element from the front end of the queue
int peek(MyQueue *q) {
        if (q->top1 == -1)
    {
        return -1;
    }
    while (q->top1 != -1)
    {
        q->stack2[++q->top2] = q->stack1[q->top1--];
    }
    int ele = q->stack1[q->top1];
    while (q->top2 != -1)
    {
        q->stack1[++q->top1] = q->stack2[q->top2--];
    }
    return ele;
}


// check if the queue is empty
bool empty(MyQueue *q) {
        if (q->top1 == -1)
    {
        return true;
    }
    return false;
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

    int n;
    scanf("%d", &n);

    int ele, correct_ele, no_of_pops;
    char operation;
    printf("%d\n",n);
    for(int i = 0; i<n; i++){
        //printf("%d", no_of_operations);
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
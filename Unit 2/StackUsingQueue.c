#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


struct queue
{
    int *qe;
    int qsize;
    int front;
    int rear;
};
typedef struct queue stack;

void initStack(stack* q, int size)
{
    q->qsize = size;
    q->front = -1;
    q->rear = -1;
    q->qe = (int*)(malloc(size*sizeof(int)));
}

int isFull(stack* q)
{
    if((q->rear == q->qsize-1 && q->front==0) || q->rear==q->front-1)
        return 1;
    return 0;
}

int isEmpty(stack* q)
{
    if(q->front==-1)
        return 1;
    return 0;
}

int dequeue(stack* q)
{
    if(isEmpty(q))
    {
        printf("Cannot dequeue\n");
        return 0;
    }
    int p = q->qe[q->front];
    if(q->front==q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
        q->front = (q->front+1)%q->qsize;
    return p;
}

void enqueue(stack* q, int ele)
// in push heavy method, each time an element is added the others are pushed forward. 
{
    if(isEmpty(q))
        q->front++;
    q->rear = (q->rear+1)%q->qsize;
    q->qe[q->rear] = ele;
}

stack pushHeavy(stack s, int ele)
{
    stack aux;
    initStack(&aux,s.qsize);
    if(isFull(&s))
    {
        printf("Stack overflow, cannot add\n");
        return s;
    }
    enqueue(&aux, ele); // first add ele to aux
    while(!isEmpty(&s))
    {
        ele = dequeue(&s);  // then copy all elements from s to aux
        enqueue(&aux, ele);
    }
    return aux;
}


void display(stack* q)
{
    if(isEmpty(q))
    {
        printf("Empty queue\n");
        return;
    }
    for(int i=q->front;i<=q->rear;i++)
    {
        printf("%d\t",q->qe[i]);
    }
    printf("\n");
}

int main()
{
    int choice, ele, n;
    stack q;
        int p;
    printf("Enter the size: ");
    scanf("%d",&n);
    initStack(&q,n);
    printf("\n1. Push\n2. Pop\n3. Display\n");
    scanf("%d",&choice);
    fflush(stdin);
    while(choice<4)
    {
        switch (choice)
        {
        case 1: printf("Enter  the element to add\n");
        scanf("%d",&ele);
        q = pushHeavy(q,ele);
            break;
        case 2: p = dequeue(&q);
        printf("Deleted %d\n",p);
        break;
        case 3: display(&q);
        break;
        default:
            break;
        }
        printf("\n1. Push\n2. Pop\n3. Display\n");
        scanf("%d",&choice);
    }

}


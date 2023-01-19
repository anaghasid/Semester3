#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Queue
{
    int* qe;
    int front;
    int rear;
    int capacity;
}queue;

void initQueue(queue* q, int size)
{
    q->capacity = size;
    q->front = -1;
    q->rear = -1;
    q->qe = (int*)(malloc(size*sizeof(int)));
}

int isFull(queue* q)
{
    if(q->rear == q->capacity-1)
        return 1;
    return 0;
}

int isEmpty(queue* q)
{
    if(q->front==-1)
        return 1;
    return 0;
}

void enqueue(queue* q, int ele)
{
    if(isFull(q))
    {
        printf("Full queue\n");
        return;
    }
    if(isEmpty(q))
        q->front++;
    q->rear++;
    //printf("Adding %d to pos %d",ele,q->front);
    q->qe[q->rear] = ele;
}

int dequeue(queue* q)
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
        q->front++;
    printf("Dequeued %d\n",p);
    return p;
}


void display(queue* q)
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

void reverseQueue(queue* q, int pos)
{
    if(pos<=(q->rear)/2)
    {
        int temp = q->qe[q->front+pos];
        q->qe[q->front+pos] = q->qe[q->rear-pos];
        q->qe[q->rear-pos] = temp;
        reverseQueue(q,pos+1);
    }
    else
        return;
}

//LINEAR QUEUE AS AN ARRAY
int main()
{
    queue q;
    int n, choice, ele;
    int p;
    printf("Enter the size: ");
    scanf("%d",&n);
    initQueue(&q,n);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    // p = dequeue(&q);
    reverseQueue(&q,0);
    display(&q);
    return 0;  
}

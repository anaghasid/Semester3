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
typedef struct queue Q;

void initQueue(Q* q, int size)
{
    q->qsize = size;
    q->front = -1;
    q->rear = -1;
    q->qe = (int*)(malloc(size*sizeof(int)));
}

int isEmpty(Q* q)
{
    if(q->front==-1)
        return 1;
    return 0;
}

int isFullC(Q* q)
{
    if(q->rear==q->front-1)
        return 1;
    else if(q->front==0 && q->rear==q->qsize-1)
        return 1;
    else
        return 0;
}

void enqueueC(Q* q, int ele)
{
    if(isEmpty(q))
    {
        q->front++;
        q->rear++;
        q->qe[q->rear] = ele;
        return;
    }
    if(isFullC(q))
    {
        printf("FULL\n");
        return;
    }
    if(q->rear != q->qsize - 1)
    {
        q->rear++;
        q->qe[q->rear] = ele;
    }
    else if(q->rear==q->qsize -1)
    {
        int f = (q->rear+1)%q->qsize;
        q->qe[f] = ele;
        q->rear = 0;
    }

}

int dequeue(Q* q)
{
    if(isEmpty(q))
    {
        printf("Empty queue, cannot dequeue\n");
        return 0;
    }
    int p = q->qe[q->front];
    
    if(q->front==q->rear)   // one element
    {
        q->front =-1;
        q->rear  =-1;
    }
    else
        q->front = (q->front+1)%q->qsize;   // generalised case. front can be size-1 or before that
    return p;
}


void display(Q* q)
{
    if(isEmpty(q))
    {
        printf("Empty queue\n");
        return;
    }
    if(q->front<=q->rear)
    {
    for(int i=q->front;i<=q->rear;i++)
    {
        printf("%d\t",q->qe[i]);
    }
    printf("\n");
    }
    else
    {
        for(int i=q->front; i<q->qsize;i++)
            printf("%d\t",q->qe[i]);
        for(int j=0; j<=q->rear;j++)
            printf("%d\t",q->qe[j]);
        printf("\n");
    }
}


int main()
{
    Q q;
    int n, choice, ele;
    int p;
    printf("Enter the size: ");
    scanf("%d",&n);
    initQueue(&q,n);
    printf("\n1. Enqueue\n2. Dequeue\n3. Display\n");
    scanf("%d",&choice);
    fflush(stdin);
    while(choice<4)
    {
        switch (choice)
        {
        case 1: printf("Enter  the element to add\n");
        scanf("%d",&ele);
        enqueueC(&q,ele);
            break;
        case 2: p = dequeue(&q);
        break;
        case 3: display(&q);
        break;
        default:
            break;
        }
        printf("1. Enqueue\n2. Dequeue\n3. Display\n");
        scanf("%d",&choice);
    }
    return 0;
}

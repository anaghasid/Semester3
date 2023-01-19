#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

/* first in first out 
Two open ends
enqueue at rear, dequeue from front
empty if front and rear=-1 (in array) or NULL (in linked list)
can become full if implemented as an array
1. linear 
2. circular
3. double ended
4. priority
increment front everytime while popping
But this is a disadvantage in linear queue because front can go forward until rear, and queue end is reached without being full.
|x|x|x| | | | |
       f     r
*/

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

int isFull(Q* q)
{
    if(q->rear == q->qsize-1)
        return 1;
    return 0;
}

int isEmpty(Q* q)
{
    if(q->front==-1)
        return 1;
    return 0;
}

void enqueue(Q* q, int ele)
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

int dequeue(Q* q)
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

void display(Q* q)
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

//LINEAR QUEUE AS AN ARRAY
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
        enqueue(&q,ele);
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

/* 
Lower the priority value, higher the priority
Highest priority dequeued first
Insert element, priority to queue from rear
While dequeuing, scan, find the highest (lowest) priority and take it out. Then push everything after that (dequeue heavy)
OR insert such that it is always ordered (enqueue heavy)
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct node
// using arrays
// linear queue
{
    int ele;
    int prio;
};
typedef struct node Node;

struct queue
{
    Node* qe;
    int qsize;
    int front;
    int rear;
};
typedef struct queue Q;

void initQ(Q* q, int size)
{
    q->qsize = size;
    q->front = -1;
    q->rear = -1;
    q->qe = (Node*)(malloc(size*sizeof(Node)));
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

int findPos(Q* q, int prior)
{
    int i=0;
    while(q->qe[i].prio<=prior && i<=q->rear)
        i++;
    return i;
}

void enqueueHeavy(Q* q,int num, int prior)
{
    int i=0;
    if(isEmpty(q))
    {
        q->front++;        
        q->qe[0].ele = num;
        q->qe[0].prio = prior;
        q->rear++;
        return;
    }
    if(isFull(q))
    {
        printf("Stack overflow, cannot add\n");
        return;
    }

    int pos = findPos(q,prior);
    for(int j=q->rear;j>=pos;j--)
    {
        q->qe[j+1].ele = q->qe[j].ele;
        q->qe[j+1].prio = q->qe[j].prio;
    }
    
    q->qe[pos].ele = num;
    q->qe[pos].prio = prior;
    q->rear++;
}

int dequeue(Q* q)
{
    if(isEmpty(q))
    {
        printf("Cannot dequeue\n");
        return 0;
    }
    int p = q->qe[q->front].ele;
    if(q->front==q->rear)
    {
        q->front = -1;
        q->rear = -1;
    }
    else
        q->front++;
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
        printf("%d\t%d\n",q->qe[i].ele,q->qe[i].prio);
    }
    printf("\n");
}

int main()
{
    Q q;
    int n, choice, ele;
    int p, priority;
    printf("Enter the size: ");
    scanf("%d",&n);
    initQ(&q,n);
    printf("\n1. Enqueue\n2. Dequeue\n3. Display\n");
    scanf("%d",&choice);
    fflush(stdin);
    while(choice<4)
    {
        switch (choice)
        {
        case 1: printf("Enter  the element and priority to add\n");
        scanf("%d",&ele);
        scanf("%d",&priority);
        enqueueHeavy(&q,ele,priority);
            break;
        case 2: p = dequeue(&q);
        printf("Deleted %d\n",p);
        break;
        case 3: display(&q);
        break;
        default:
            break;
        }
        printf("1. Enqueue\t2. Dequeue\t3. Display\n");
        scanf("%d",&choice);
    }
    return 0;  
}

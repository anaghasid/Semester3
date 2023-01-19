// CIRCULAR QUEUE USING LINKED LISTS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct qnode
{
    int ele;
    struct qnode* link;
};

struct queue
{
    struct qnode *front;
    struct qnode *rear;  
};
typedef struct queue Q;

void initQueueC(Q* q)
{
    q->front = NULL;
    q->rear = NULL;
}

int isEmptyCL(Q* q)
{
    if(q->front==NULL)
        return 1;
    return 0;
}

void enqueueCL(Q* q,int e)
{
    struct qnode *temp;
    temp = (struct qnode*)malloc(sizeof(struct qnode));
    temp->ele = e;
    temp->link = NULL;
    if(isEmptyCL(q))
    {
        q->front = temp;
        q->rear = temp;
        temp->link = temp;
    }
    else
    {
        q->rear->link = temp;
        q->rear = temp;
        temp->link = q->front;
    }
}

int dequeueCL(Q* q)
{
    if(isEmptyCL(q))
    {
        printf("Empty queue\n");
        return 0;
    }
    int res = q->front->ele;
    struct qnode* frnode = q->front;
    if(q->front == q->rear)
    {
        free(frnode);
        q->front = NULL;
        q->rear = NULL;
        return res;
    }
    q->front = q->front->link;
    q->rear->link = q->front;
    free(frnode);
    return res;
}

void displayCL(Q* q)
{
    struct qnode* pres = q->front;
    if(q->front != q->rear)
    
    while(pres->link!=q->front)
    {
        printf("%d\t",pres->ele);
        pres = pres->link;
    }
    printf("%d\t",pres->ele);
    printf("\n");
}

int main()
{
    Q qu;
    int choice, ele;
    int num;
    initQueueC(&qu);
    printf("\n1. Enqueue\n2. Dequeue\n3. Display\n");
    scanf("%d",&choice);
    fflush(stdin);
    while(choice<4)
    {
        switch (choice)
        {
        case 1: printf("Enter  the element to add\n");
        scanf("%d",&ele);
        enqueueCL(&qu, ele);
            break;
        case 2: num = dequeueCL(&qu);
        printf("Deleted %d\n",num);
        break;
        case 3: displayCL(&qu);
        break;
        default:
            break;
        }
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n");
        scanf("%d",&choice);
    }
    return 0;
}

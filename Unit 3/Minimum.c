// Level ordered treee with the help of queue that dequeues after node with children is created 
// INCOMPLETE
#include<stdio.h>
#include<stdlib.h>

struct node{
    int key;
    struct node *lchild;
    struct node *rchild;
};
typedef struct node node;

struct btree
{
    node *troot;
};
typedef struct btree bintree;

typedef struct queue
{
    int front;
    int rear;
    node*  ptr[20]; // queue stores pointer to new value and joins
}Q;


void initBinTree(bintree* btree)
{
    btree->troot = NULL;
}

void initQueue(Q* que)
{
    que->front = -1;
    que->rear = -1;
}

node* createNode(int ele)
{
    if(ele==-1)
        return NULL;
    node* newnode = (node*)malloc(sizeof(node*));
    newnode->key = ele;
    newnode->lchild = NULL;
    newnode->rchild = NULL;
    return newnode;
}

node* dequeue(Q* que)
{
    node* temp;
    if(que->front==-1)
        return NULL;
    temp = que->ptr[que->front];
    if(que->front == que->rear)
    {
        que->front = -1;
        que->rear = -1;
    }
    else
        que->front++;
    return temp;
}

void insert(Q* qu, node* newnode)
{
    // insert rear
    if(qu->front == -1)
        qu->front++;
    qu->rear++;
    qu->ptr[qu->rear] = newnode;
}

void create(bintree* b)
{
    // level ordered creation, preordered traversal 
    int data;
    node* newnode;
    Q* que;
    initQueue(que);
    printf("Enter the node data and -1 to stop: ");
    scanf("%d",&data);
    if(data==-1)
    {
        return;
    }
    node* cur;
    newnode = (node*)malloc(sizeof(node));
    newnode->key = data;
    newnode->lchild = NULL;
    newnode->rchild = NULL;
    insert(que,newnode);
    while(que->front!=-1)    
    {
        cur = dequeue(que);
        printf("\n Enter the left child of %d: ",cur->key);
        scanf("%d",&data);
        cur->lchild = createNode(data);
        if(cur->lchild!=NULL)
            insert(que,cur->lchild);
        printf("\n Enter the right child of %d: ",cur->key);
        scanf("%d",&data);
        cur->rchild = createNode(data);
        if(cur->rchild!=NULL)
            insert(que,cur->rchild);
    }
}

void findmin(node* root, int* min)
{
    if(root==NULL)
        return;
    if(*min>root->key)
        min = root->key;
    findmin(root->lchild,min);
    findmin(root->rchild,min);    
}

void preorder(node* root)
{
    node* temp = root;
    if(temp==NULL)
        return;
    printf("%d\t",root->key);
    preorder(root->lchild);
    preorder(root->rchild);
}

int main()
{
    bintree binaryT;
    int min = 9999;
    initBinTree(&binaryT);
    create(&binaryT);
    printf("Preordered traversal\n");
    preorder(binaryT.troot);
    findmin(binaryT.troot,&min);
    return 0;
}

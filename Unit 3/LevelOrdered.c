// Level ordered tree with the help of queue that dequeues after node with children is created 

// FUNCTION CREATE IS LEVEL ORDERED CREATION : currently not in working order
// levelOrdered IS FOR LEVEL ORDERED TRAVERSAL
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
    node* node_arr[20]; // queue stores pointer to new value and joins
    // array of pointers with front and rear storing respective indexes
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

int isEmpty(Q* q)
{
    if(q->front==-1 && q->rear==-1)
        return 1;
    return 0;
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


node* insertToSearch(node* root, int ele)
{
    if(root==NULL)
    {
        root = createNode(ele);
        return root;
    }
    if(ele<root->key)   // insert of left if lesser than node
    {
        root->lchild = insertToSearch(root->lchild,ele);
    }
    else if(ele>root->key){
        root->rchild = insertToSearch(root->rchild,ele);
    }
    else
        printf("Data is duplicate\n");
    return root;
}

node* dequeue(Q* que)
{
    node* temp;
    if(que->front==-1)
        return NULL;
    temp = que->node_arr[que->front];
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
    if(newnode==NULL)
        return;
    // insert to queue: rear
    if(qu->front == -1)
        qu->front++;
    qu->rear++;
    qu->node_arr[qu->rear] = newnode;
}

node* create(bintree* b)
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
        return NULL;
    }
    node* cur, *root=NULL;;
    newnode = (node*)malloc(sizeof(node));
    newnode->key = data;
    newnode->lchild = NULL;
    newnode->rchild = NULL;
    insert(que,newnode);
    root = newnode;
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
    return root; 
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

void levelOrdered(Q* q)
{
    node* cur;
    // root is already inserted
    while(!isEmpty(q))
    {
        cur = q->node_arr[q->front];
        printf("%d\t",cur->key);
        insert(q,cur->lchild);
        insert(q,cur->rchild);
        dequeue(q);
    }
}

int main()
{
    bintree binaryT;
    Q* q = (Q*)malloc(sizeof(Q));
    printf("hi1\n");
    initQueue(q);
    initBinTree(&binaryT);
    int data;
    int flag = 1;
    while(flag)
    {
        printf("Enter the node value and -1 to stop: ");
        scanf("%d",&data);
        if(data==-1)
            flag=0;
        else
        {
            binaryT.troot = insertToSearch(binaryT.troot,data);
        }
    }
    insert(q,binaryT.troot);
    printf("Head of queue is %d\n",q->node_arr[0]->key);
    printf("Level ordered traversal\n");
    levelOrdered(q);
    return 0;
}

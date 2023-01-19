// using two stacks
// https://www.geeksforgeeks.org/zigzag-tree-traversal/

// UGGHHH SEGMENTATION FAULT WHEN REFERENCING STACK->TOP !
#include<stdio.h>
#include<stdlib.h>
#define MAX 20

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

struct stack
{
    node* stackele[MAX];    // array of node pointers
    int top;
};
typedef struct stack Stack;

int isEmptyStack(Stack* s)
{
    if(s->top==-1)
        return 1;
    return 0;
}

void initStack(Stack* s,int size)
{
    printf("inside initstack\n");
    s->top = 0;
    printf("%d\n",s->top);
}

int isFullStack(Stack* s)
{
    if(s->top == MAX-1)
        return 1;
    return 0;
}

void push(Stack* s, node* ele)
{
    if(isFullStack(s)==1)
        printf("Overflow, cannot push\n");
    else
    {
        s->top++;
        s->stackele[s->top] = ele;
    }
}

void pop(Stack *s)
{
    if(isEmptyStack(s)==1)
        printf("No elements, cannot pop\n");
    else{
        s->top--;
    }
}


void displayStack(Stack* s)
{
    for(int i=0;i<=s->top;i++)
    {
        printf("%d\t",s->stackele[i]);
    }
    printf("\n");
}


void initBinTree(bintree* btree)
{
    btree->troot = NULL;
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


void preorder(node* root)
{
    node* temp = root;
    if(temp==NULL)
        return;
    printf("%d\t",root->key);
    preorder(root->lchild);
    preorder(root->rchild);
}

void ziglevelOrdered(Stack* cur, Stack* next, int level)
{
    node *lchild, *rchild;
    // root is already pushed into current stack
    while(!isEmptyStack(cur))
    {
        lchild = (cur->stackele[cur->top])->lchild;
        rchild = (cur->stackele[cur->top])->rchild;
        if(level%2==0)
        {
            push(next,lchild);
            push(next,rchild);
        }
        else
        {
            push(next,rchild);
            push(next,lchild);
        }
        pop(cur);
    }
    ziglevelOrdered(next,cur,level+1);      // swap current and next stacks, increment level
}

int main()
{
    bintree binaryT;
    Stack *curs, *nexts;
    initStack(curs,20);
    printf("Hi2\n");
    initStack(nexts,20);
    initBinTree(&binaryT);
    printf("Hi3\n");
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
    push(curs,binaryT.troot);
    printf("Zig zag level ordered traversal:\n");
    ziglevelOrdered(curs,nexts,0);  
    return 0;
}

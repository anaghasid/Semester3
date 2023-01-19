/* */

#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *lchild;
    struct node *rchild;
};
typedef struct node node;

struct btree
{
    node *troot;
};
typedef struct btree bintree;

void initBinTree(bintree* btree)
{
    btree->troot = NULL;
}

node* createBinTree(bintree* btree)
{
    node* p;
    int data;
    scanf("%d",&data);
    if(data==-1)
    {
        return NULL;
    }
    p = (node*)malloc(sizeof(node));
    p->info = data;
    p->lchild = NULL;
    p->rchild = NULL;
    if(btree->troot==NULL)
    {
        btree->troot = p;
    }
    printf("Enter left child of %d: ",p->info);
    p->lchild = createBinTree(btree);       // recursive call until all lchildren are reached.
    printf("Enter the right child of %d: ",p->info);
    p->rchild = createBinTree(btree);
    return p;
}

void preorder(node* cur)
{
    if(cur==NULL)
        return;
    // Node, left, right
    printf("%d\t",cur->info);
    preorder(cur->lchild);
    preorder(cur->rchild);
}

void inorder(node* cur)
{
    if(cur==NULL)
        return;
    inorder(cur->lchild);
    printf("%d\t",cur->info);
    inorder(cur->rchild);
}

void postorder(node *cur)
{
    if(cur==NULL)
        return;
    printf("Preordered tree:\n");
    postorder(cur->lchild);
    postorder(cur->rchild);
    printf("%d\t",cur->info);
    // postorder(cur->)
}

int main()
{   
    bintree root;
    initBinTree(&root);
    printf("enter the node info and -1 for NULL:  ");
    root.troot = createBinTree(&root);
    printf("Preordered tree:\n");
    preorder(root.troot);
    return 0;
}

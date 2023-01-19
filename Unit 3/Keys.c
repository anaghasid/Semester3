/*
binary search tree with key elements
Properties like: height, number of leaf nodes, non leaf
Mirroring
*/

#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int key;
    struct node *lchild;
    struct node *rchild;
}node;

struct btree
{
    node *troot;
};
typedef struct btree bst;

void initSearch(bst* tree)
{
    tree->troot = NULL;
}

node* createNode(int data)
{
    node* newnode = (node*)malloc(sizeof(node));
    newnode->key = data;
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

int findMinimum(node* root)
{
    node* cur = root;
    if(root==NULL)
        return 0;
    while(cur->lchild!=NULL)
        cur = cur->lchild;
    return cur->key;
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


void inorder(node* cur)
{
    if(cur==NULL)
        return;
    inorder(cur->lchild);
    printf("%d\t",cur->key);
    inorder(cur->rchild);
}

// to find height of tree. Find height of left and right subtrees, and add one. Do this recursively
int height(node* root)
{
    int l=0, r=0;
    if(root==NULL)
        return 0;
    l = height(root->lchild);
    r = height(root->rchild);
    if(l>r)
        return l+1;
    return r+1;  
}

int leafNodes(node* root)
{
    int l=0, r=0;
    if(root!=NULL)
    {
        if(root->lchild==NULL && root->rchild==NULL)
            return 1;
        l = leafNodes(root->lchild);
        r = leafNodes(root->rchild);
    }
    return l+r;
}

int nonLeafNodes(node* root)
{
    if(root==NULL || root->lchild==NULL && root->rchild==NULL)
        return 0;
    return(nonLeafNodes(root->lchild) + 1+ nonLeafNodes(root->rchild));
}

int totalNodes(node* root)
{
    int l=0, r=0;
    if(root==NULL)
        return 0;
    l = totalNodes(root->lchild);
    r = totalNodes(root->rchild);
    return l+r+1;       // left + right children + parent itself
}

void mirror(node* root)
{
    node* temp = NULL;
    if(root==NULL)
        return;
    temp = root->lchild;
    root->lchild = root->rchild;
    root->rchild = temp;
    mirror(root->lchild);
    mirror(root->rchild);
}

int main()
{
    int data;
    bst search_tree;
    initSearch(&search_tree);
    int flag = 1;
    while(flag)
    {
        printf("Enter the node value and -1 to stop: ");
        scanf("%d",&data);
        if(data==-1)
            flag=0;
        else
        {
            if(search_tree.troot==NULL)
                search_tree.troot = insertToSearch(search_tree.troot,data);
            else
                insertToSearch(search_tree.troot,data);
        }
    }
    printf("Inordered traversal\n");
    inorder(search_tree.troot);
    printf("\n");
    printf("The height of the tree is %d\n",height(search_tree.troot));
    printf("Number of leaf nodes is %d\n",leafNodes(search_tree.troot));
    printf("The number of non leaf nodes is %d\n",nonLeafNodes(search_tree.troot));
    printf("The total number of nodes is %d\n",totalNodes(search_tree.troot));
    mirror(search_tree.troot);
    printf("After swapping\n");
    inorder(search_tree.troot);
    return 0;
    
}

// Binary search tree. Inordered traversal gives sorted 
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
    {
        cur = cur->lchild;
    }
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
    printf("Preordered traversal\n");
    preorder(search_tree.troot);
    printf("\nThe minimum value is %d\n",findMinimum(search_tree.troot));
    return 0;
    
}

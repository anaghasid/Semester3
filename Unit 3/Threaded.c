#include<stdio.h>
#include<stdlib.h>
/*
IN THREADED BINARY SEARCH TREE
leaf nodes are connected back, not null
Left child to inorder predecessor  (if child does not exist)
Right child to inorder successor (if child does not exist)
While inserting, newnode->lchild = parent->lchild
    (if it is left child, it'll point to parent's parent. If it's right child, it'll point to left sibling)
    newnode->rchild = parent
*/
typedef struct node
{
    int key;
    struct node* lchild;
    struct node* rchild;
    int lthread;    // 0 if it has real children. 1 for threads
    int rthread;
}node;

node* insert(node* root, int data)
{
    node* ptr = root, *parent = NULL;
    node* newnode;
    newnode = (node*)malloc(sizeof(node));
    newnode->key=data;
    newnode->lchild = NULL;
    newnode->rchild = NULL;
    newnode->rthread = 1;
    newnode->lthread = 1;
    if(root==NULL)
        return newnode;
    while(ptr!=NULL)
    {
        if(data==ptr->key)
        {
            printf("Duplicate value, no insertion\n");
            return root;
        }
        parent = ptr;

        if(data<ptr->key)
        {
            if(ptr->lthread==0)     // ptr has left child
                ptr = ptr->lchild;
            else
                break;      // newnode will be inserted as lchild of ptr
        }
        else
        {
            if(ptr->rthread==0)
                ptr = ptr->rchild;
            else
                break;
        }

    }
    if(data<parent->key)
    {
        newnode->lchild = parent->lchild;
        newnode->rchild = parent;
        parent->lchild = newnode;
        parent->lthread = 0;
    }
    else{
        newnode->rchild = parent->rchild;
        newnode->lchild = parent;
        parent->rchild = newnode;
        parent->rthread = 0;
    }
    return root;
}

node* inorderSuccessor(node* ptr)
{
    // if it has right thread to some node, return that
    // else return leftmost in right subtree
    if(ptr->rthread == 1)       // no right child, then return threaded child
        return ptr->rchild;
    ptr = ptr->rchild;
    while(ptr->lthread == 0)    // if it has a right child, return the leftmost child of rchild 
        ptr = ptr->lchild;
    return ptr;
}

void inorder(node* root)
{
    node* ptr = root;
    if(root==NULL)
    {
        printf("\nEmpty Tree\n");
        return;
    }
    while(ptr->lthread==0)
        ptr = ptr->lchild;      // start from the leftmost
    while(ptr!=NULL)
    {
        printf("%d\t",ptr->key);
        ptr = inorderSuccessor(ptr);
    }
}
int main()
{
    node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 80);
    root = insert(root, 70);
    root = insert(root, 99);
    root = insert(root, 55);
    inorder(root);
    return 0;
}
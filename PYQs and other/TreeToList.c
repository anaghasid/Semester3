/*
from a binary search tree, put all keys into a linked list in ASCENDING ORDER
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

typedef struct list
{
    int data;
    struct list* link;
}list_node;

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

// linked list functions:
list_node *createlist(list_node *head)
{
    head=NULL;
    return head;
}

list_node *InsertRear(list_node *head,int ele)
{
    list_node *newnode=NULL,*cur; //creating a new node so head points to that and that again points to first ele
    newnode=(list_node *)malloc(sizeof(list_node));
    newnode->data=ele;
    newnode->link=NULL;
    cur=head;
    if(head==NULL){
        head=newnode;
    }
    else{
        while(cur->link!=NULL)
            cur=cur->link;
        cur->link=newnode;
    }
    return head;
}

void displayList(list_node* head)
{
    list_node* pres = head;
    while(pres!=NULL)
    {
        printf("%d\t",pres->data);
        pres = pres->link;
    }
    printf("\n");
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


void inorder(node* cur)
{
    if(cur==NULL)
        return;
    inorder(cur->lchild);
    printf("%d\t",cur->key);
    inorder(cur->rchild);
}

list_node* convertToList(node* cur,list_node* newlist)
{
    if(cur==NULL)
        return newlist;
    newlist = convertToList(cur->lchild,newlist);
    newlist = InsertRear(newlist,cur->key);
    newlist = convertToList(cur->rchild,newlist);
    return newlist;
}



int main()
{
    int data;
    bst search_tree;
    initSearch(&search_tree);
    search_tree.troot = insertToSearch(search_tree.troot,70);
    search_tree.troot = insertToSearch(search_tree.troot,60);
    search_tree.troot = insertToSearch(search_tree.troot,90);
    search_tree.troot = insertToSearch(search_tree.troot,80);
    search_tree.troot = insertToSearch(search_tree.troot,30);
    search_tree.troot = insertToSearch(search_tree.troot,65);
    search_tree.troot = insertToSearch(search_tree.troot,80);
    search_tree.troot = insertToSearch(search_tree.troot,100);
    search_tree.troot = insertToSearch(search_tree.troot,85);
    search_tree.troot = insertToSearch(search_tree.troot,20);
    printf("Inordered traversal\n");
    inorder(search_tree.troot);
    printf("\n");
    printf("Inside the list\n");
    list_node* newlist = (list_node*)malloc(sizeof(list_node));
    newlist = createlist(newlist);
    newlist = convertToList(search_tree.troot,newlist);
    displayList(newlist);
    return 0;
    
}

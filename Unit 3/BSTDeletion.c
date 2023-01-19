// Deletion of node
/*
3 cases:
. Leaf node
. Node that has 1 child: change link of parent to the single child
. Node that has 2 children: swapping with inorder successor (maixmum on left) and using the two above 
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
    if(ele<root->key) 
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

int findmin(node* root)
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

node* deleteNode(node* root, int ele)
{
    node* temp = NULL;
    if(root==NULL)  // also handles invalid data condition
        return NULL;

    // search equivalent
    if(ele<root->key)
    {
        root->lchild = deleteNode(root->lchild,ele);
    }
    else if(ele>root->key)
        root->rchild = deleteNode(root->rchild,ele);
    

    // node to be deleted
    else
    {
        if(root->lchild==NULL)  // one child
        {
            temp = root->rchild;    // could be null or the left child
            free(root);
            return temp;    // also handles leaf node condition
        }
        else if(root->rchild==NULL)
        {
            temp = root->lchild;
            free(root);
            return temp;
        }

        else
        {
            // find inordered successor. It either is a leaf node or has only the right child
            root->key = findmin(root->rchild);
            root->rchild = deleteNode(root->rchild, root->key);     // delete the node that it has been replaced with

            /*
            // to replace with inorder predeccessor:
                root->key = findmax(rot->lchild);
                root->lchild = deleteNode(root->lchild, root->key);
            */
        }
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


void inorder(node* cur)
{
    if(cur==NULL)
        return;
    inorder(cur->lchild);
    printf("%d\t",cur->key);
    inorder(cur->rchild);
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
    deleteNode(search_tree.troot,80);
    printf("After deleting 80\n");
    inorder(search_tree.troot);
    return 0;
    
}


#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    char op;
    struct node *lchild;
    struct node *rchild;
}btree;


typedef struct stack
{
    btree *ele[20];
    int top;
}stack;


void initSearch(btree* tree)
{
    tree = NULL;
}

btree* createbtree(char data)
{
    btree* newnode = (btree*)malloc(sizeof(btree));
    newnode->op = data;
    newnode->lchild = NULL;
    newnode->rchild = NULL;
    return newnode;
}

void preorder(btree* root)
{
    btree* temp = root;
    if(temp==NULL)
        return;
    printf("%c",root->op);
    preorder(root->lchild);
    preorder(root->rchild);
}

btree* createNode(char op)
{
    btree* newnode;
    newnode = (btree*)malloc(sizeof(btree));
    newnode->lchild = NULL;
    newnode->rchild = NULL;
    newnode->op = op;
}

btree* buildTree(btree* head, char* postfix)
{
    btree *newnode, *lop, *rop;
    int length = strlen(postfix);
    stack stk;
    initStack(&stk);    //WRITE
    for(int i=0;i<length;i++)
    {
        if(isOperator(postfix[i]))
        {
            newnode = createNode(postfix[i]);
            rop = pop(&stk);
            lop = pop(&stk);
            newnode->lchild = lop;
            newnode->rchild = rop;
            push(&stk,newnode);
        }
        else
        {
            newnode = createNode(postfix[i]);
            push(&stk,newnode);
        }
    }
    return pop(&stk);   // head
}

int evaluate(btree* root)
{
    if(isOperator(root->op))
    {
        switch(root->op)
        {
            case '+': evaluate(root->lchild) + evaluate(root->lchild);
                break;
            case '-': evaluate(root->lchild) - evaluate(root->rchild);
                break;
            case '*': evaluate(root->lchild)*evaluate(root->rchild);
            break;
            case '/': evaluate(root->lchild)/evaluate(root->rchild);
            break;
            default: return root->op - '0';     // if node is a number, it gives its value
        }
    }
}

int main()
{
    char *exp[20];
    btree* root = NULL;
    int result;
    printf("Enter the postfix expression: ");
    scanf("%s",&exp);
    root = buildTree(root,exp);
    result = evaluate(root);
    return 0;
}
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int hash_fun(int value)
{
    return value%5;
}
void insertIntoHash(int size, int value, struct node** chain)
{
    int datakey, index;
    struct node *newnode, *cur;
    index = hash_fun(value);
    newnode = (struct node*)malloc(sizeof(struct node*));
    newnode->data = value;
    cur = chain[index];
    printf("Check2\n");
    if(cur!=NULL)
    {
    while(cur->next!=NULL)
        cur = cur->next;
    newnode->next = NULL;
    cur->next = newnode;
    }
    else
    {
        chain[index] = newnode;
    }
}

void print(int size, struct node** chain)
{
    int i;
    for(i = 0; i < size; i++)
    {
        struct node *temp = chain[i];
        printf("[%d]",i);
        while(temp)
        {
            printf("->%d",temp->data);
            temp = temp->next;
        }
        printf("->NULL\n");
    }
}

void createHash(int size, int *stk, int n, struct node** chain)
{
    for(int i=0;i<n;i++){
        insertIntoHash(size, stk[i], chain);
    }
}

int main()
{
    int i;
    int size;
    scanf("%d", &size);

    struct node *chain[size];

    for(i = 0; i < size; i++){
        chain[i] = NULL;
    }

    int n;
    scanf("%d", &n);

    int stk[n];
    for(int k=0;k<n;k++){
        scanf("%d", &stk[k]);
    }

    createHash(size, stk, n, chain);
    print(size, chain);

    return 0;
}
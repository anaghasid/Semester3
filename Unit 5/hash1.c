// separate chaining has a linked list in case of collisions containing all values that give that key
// linear probing: colliding record moves to different keys until any one is empty. If no empty, then it cannot be inserted. Causes clustering.
// quadratic probing: movement is quadratic (1,4,9...)
// double hashing: use two hashing functions

#include<stdio.h>
#include<stdlib.h>
#define Max 10

struct record 
{
    int key;
    int info;
    struct record* next; // for separate chaining
};
typedef struct record record;

int hash_fun(int datakey)
{
    // key%10 is the function
    return datakey%Max;
}

void insert(record* hashtable[])
{
    int datakey, index;
    int datainfo;
    record *newnode, *cur;
    printf("Enter the key and info: ");
    scanf("%d %d",&datakey,&datainfo);
    index = hash_fun(datakey);
    newnode = (record*)malloc(sizeof(record));
    newnode->key = datakey;
    newnode->info = datainfo;
    newnode->next = hashtable[index];
    hashtable[index] = newnode;
}

void search(record* hashtable[])
{
    int skey, index;
    record* cur;
    printf("enter the record key: ");
    scanf("%d",&skey);
    index = hash_fun(skey);
    cur = hashtable[index];
    if(cur==NULL)
    {
        printf("record not found :(\n");
        return;
    }
    while(cur!=NULL)
    {
        if(cur->key==skey)
        {
            printf("Record found! Info is %d",cur->info);
            return;
        }
        cur = cur->next;
    }
    printf("Record not found :(\n");
}

void display(record* hashtable[])
{
    for(int i=0;i<Max;i++)
    {
        record* cur = hashtable[i];
        printf("%d\t",i);
        while(cur!=NULL)
        {
            printf("(%d,%d)\t",cur->key,cur->info); 
            cur = cur->next;

        }
        printf("\n");
    }
}

void delete(record *hashtable[]){
    record *curr,*prev;
    int dkey;
    printf("enter the data key to delete:");
    scanf("%d",&dkey);
    int index=hash_fun(dkey);
    prev=NULL;
    curr=hashtable[index];
    if(curr==NULL){
        printf("Record not found:(\n");
        return;
    }
    while (curr!=NULL)
    {
        if(curr->key==dkey){
            if(prev==NULL){
                hashtable[index]=curr->next;
                free(curr);
                return;
            }
            prev->next=curr->next;
            free(curr);
            return;
        }
        prev=curr;
        curr=curr->next;
    } 

}

int main()
{
    record *hashtable[Max];
    int option;
    for(int i=0;i<Max;i++)
        hashtable[i] = NULL;
    while(1)
    {
        printf("\t1. Insert\t2. Search\t3. Delete\t4. Display\t5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&option);
        switch(option)
        {
            case 1: insert(hashtable);
                break;
            case 2: search(hashtable);
            break;
            case 3: delete(hashtable);
            break;
            case 4: display(hashtable);
            break;
            case 5: exit(0);
        }
    }
}
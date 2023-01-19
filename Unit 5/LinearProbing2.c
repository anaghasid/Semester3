#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max 20

struct dataitem
{
    int key;
    float var;
    char info[10];
};
typedef struct dataitem record;


int hash_fun(int datakey)
{
    // key%10 is the function
    return datakey%Max;
}

void insert(record* hashtable)
{
    int newkey, index;
    int newvar;
    char newinfo[10];
    record *newnode, *cur;
    printf("Enter the key: ");
    scanf("%d",&newkey);
    printf("Enter the new var and info: ");
    scanf("%d %s",&newvar, newinfo);
    index = hash_fun(newkey);
    for(int i=0;i<Max;i++)
    {
        if(hashtable[i].key==-1)
        {
            hashtable[i].key = newkey;
            hashtable[i].var = newvar;
            strcpy(hashtable[i].info,newinfo);
            return;
        }
        index = (index+1)%Max;
    }
}

void search(record hastable[])
{
    int skey;
    int index;
    printf("Enter the record key to search: ");
    scanf("%d",&skey);
    

}

int main()
{
    record hashtable[Max];
    int option;
    for(int i=0;i<Max;i++)
    {
        hashtable[i].key = -1;
    }
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

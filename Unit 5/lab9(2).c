#include <stdio.h>
#include<stdlib.h>
#define SIZE 13


int hash_fun1(int value)
{
    return value%SIZE;
}

int hash_fun2(int value)
{
    return 11-(value%11);
}


void insertIntoHash(int key, int *hashtable)
{
    int index = hash_fun1(key);
    if(hashtable[index]==0)
    {
        hashtable[index] = key;
        return;
    }
    int i=0;    // SHOULD IT START FROM 1?
    while(hashtable[index]!=0)
    {
        index = (hash_fun1(key) + i*hash_fun2(key))%SIZE;
        i++;
        if(i==SIZE)
        {
            printf("-1\n");
            return;
        }
    }
        hashtable[index] = key;
}

void printHashTable(int *hashtable)
{
    for(int i=0;i<SIZE;i++)
    {
        printf("%d "hashtable[i]);
    }
}

int main()
{
    int i;
    int h[SIZE]={0};

    int n;
    scanf("%d", &n);

    int stk[n];
    for(int k=0;k<n;k++){
        scanf("%d", &stk[k]);
    }

    for(int i=0;i<n;i++){
        insertIntoHash(stk[i], h);
    }

    printHashTable(h);

    return 0;
}
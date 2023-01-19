/*
    Insertion
*/
#include<stdio.h>
#include<stdlib.h>
#define Max 50


void minheapify(int* heap, int i , int n)
{
    // all changes in the array only
    int lchild, rchild;
    int min = i;    // assuming that parent at i is the minimum
    lchild = 2*i+1; //positions
    rchild = 2*i+2;
    if(lchild<n)
    {
        if(rchild<n)
        {
        if(heap[lchild]<heap[rchild] && heap[lchild]<heap[min])   // WRONG: CHECK CONDITION FOR RCHILD < N
            min = lchild;
        }
        else
        {
            if(heap[lchild]<heap[min])
                min = lchild;
        }
    }
    if(rchild<n)
    {
        if(heap[rchild]<heap[min])
            min = rchild;
    }
    if(min!=i)
    {
      int temp;
        temp = heap[i];
        heap[i] = heap[min];
        heap[min] = temp;
        minheapify(heap,min,n);
    }
}

void buildMinHeap(int* heap, int n)
{
    int i;
    for(int i=n/2-1;i>=0;i--)   // all parent nodes
    {
        minheapify(heap, i, n);
    }
}

void insert(int* heap, int ele, int* n)
{
    int i = *n;
    heap[*n] = ele;     // insert at last position
    *n = *n+1;
    int temp;
    while(i!=0 && heap[i]<heap[(i-1)/2])        // only check current child and parent, no need of comparing with sibling
    {
        temp = heap[i];
        heap[i] = heap[(i-1)/2];
        heap[(i-1)/2] = temp;
        i = (i-1)/2;
    }

}

int delete(int heap[], int* n)
{
    int min = heap[0];
    heap[0] = heap[*n-1];
    *n = *n-1;
    minheapify(heap,0,*n);
    return min;
}

// top down approach. Successive insertion


int main()
{
    int n, ele;
    int heap[Max];
    int size;
    printf("\nEnter the size of the heap: ");
    scanf("%d",&n);
    for(int j=0;j<n;j++)
    {
        scanf("%d",&ele);
        size = j;
        insert(heap,ele,&size);
    }
    for(int j=0;j<n;j++)
    {
        printf("%d\t",heap[j]);
    }
    return 0;
}

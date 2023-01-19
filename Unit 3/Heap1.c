// Heap sort has nlogn complexity, not n^2 as in the others
// in a min heap, parent has a lower value than children
/*
Complete binary tree
store all elements in array, keep swapping children and parents from bottom if parents are greater than children: bottom up approach

Top down approach: successive insertion. As left child is inserted, check if it is greater than parent, then insert right child and check
In the array, for parent at i: left child at 2i+1, right at 2i+2 
while inserting a new element, insert as last leaf node, check with parent (not sibling), and heapify again

Deleting: removes the parent and replaces with last leaf node (last element in array) and heapifies top down

Applications: priority queue
*/

// BOTTOM UP HEAP

#include<stdio.h>
#include<stdlib.h>
#define Max 50


void minheapify(int* heap, int i , int n)
{
    // index starts from 0
    // all changes in the array only
    int lchild, rchild;
    int min = i;    // assuming that parent at i is the minimum
    lchild = 2*i+1; //i, min, lchild, rchild are all positions
    rchild = 2*i+2;
    if(lchild<n)
    {
        if(rchild<n)
        {
            if(heap[lchild]<heap[rchild] && heap[lchild]<heap[min])   
                min = lchild;     
            if(heap[lchild]>heap[rchild] && heap[rchild]<heap[min])
                min = rchild;
        }
        else
        {
            // no condition of only having a righ child because complete tree
            if(heap[lchild]<heap[min])
                min = lchild;
        }
    }
    if(min!=i)
    {
        int temp;
        temp = heap[i];
        heap[i] = heap[min];
        heap[min] = temp;
        minheapify(heap,min,n);     // after swapping, check if the swapped element is the least
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



int main()
{
    int n;
    int heap[Max];
    printf("\nEnter the size of the heap: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&heap[i]);
    }
    buildMinHeap(heap,n);
    // printf("The heap in preorder is \n");
    for(int j=0;j<n;j++)
    {
        printf("%d\t",heap[j]);
    }
    printf("\n");
    return 0;
}

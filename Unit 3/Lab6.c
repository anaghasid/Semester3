#include <stdio.h>
#include <stdlib.h>

typedef struct MinHeap MinHeap;
struct MinHeap {
    int* arr;
    int size;  //size of the heap
};


MinHeap* init_minheap(int size) {
    MinHeap* minheap = (MinHeap*)calloc(1, sizeof(MinHeap));
    minheap->size = size;
    minheap->arr = (int*)calloc(size, sizeof(int));
    return minheap;
}

void minheapify(int* heap, int i , int n)
{
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
        
        }
        else
        {
            if(heap[lchild]<heap[min])
                min = lchild;
        }
    }
    if(rchild<n)
    {
        if(heap[lchild]>heap[rchild] && heap[rchild]<heap[min])
            min = rchild;
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

void create_minheap(MinHeap *heap) 
{   
    int i;
    for(int i=(heap->size)/2-1;i>=0;i--)   // all parent nodes
    {
        minheapify(heap->arr, i, heap->size);
    }
}


void print_minheap(MinHeap* heap) 
{
    for(int i=0;i<(heap->size);i++)
        printf("%d ",heap->arr[i]);
}

void free_minheap(MinHeap* heap) {
    if (!heap)
        return;
    free(heap->arr);
    free(heap);
}

int main() {

    int capacity; 
    scanf("%d", &capacity);
    MinHeap* heap = init_minheap(capacity); //number of elements 
    int i=0;
    while(i < capacity){
        scanf("%d", &heap->arr[i++]);

    }
    create_minheap(heap);
    print_minheap(heap);
    free_minheap(heap);
    return 0;
}
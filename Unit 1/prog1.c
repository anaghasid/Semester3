#include<stdio.h>
#include<stdlib.h>

void read2d(int** ptr, int rsize, int* csize);
void freearr(int** ptr, int rsize, int *csize);
int main()
{
    int **ptr;
    //allocate memory for 2D array dynamically
    int rsize;
    int csize[5] = {2,5,2,8,1};
    rsize = 5;
    //JAGGED ARRAY
    ptr = (int**)malloc(rsize*sizeof(int*));
    for(int i=0;i<rsize;i++)
    {
        ptr[i] = (int*)malloc((csize[i])*sizeof(int));
    }
    
    read2d(ptr,rsize,csize);
    freearr(ptr,rsize,csize);
    return 0;

}

void read2d(int** ptr, int rsize, int* csize)
{
    for(int i=0;i<rsize;i++)
    {
        for(int j=0;j<csize[i];j++)
        {
            scanf("%d",(*(ptr+i))+j);
            //ptr[i][j] = i+j;
            printf("%d\t",ptr[i][j]);
        }
        printf("\n");
    }
}


void freearr(int** ptr, int rsize, int *csize)
{
        for(int i=0;i<rsize;i++)
    {
        free(ptr[i]);
    }
}

/*#include<stdio.h>
#include<stdlib.h>

void read2d(int** ptr, int rsize, int csize);
int main()
{
    int **ptr;
    //allocate memory for 2D array dynamically
    int rsize, csize;
    rsize = 10;
    csize = 10;
    ptr = (int**)malloc(rsize*sizeof(int*));
    for(int i=0;i<rsize;i++)
    {
        ptr[i] = (int*)malloc((csize-i)*sizeof(int)); //jagged array
    }
    read2d(ptr,rsize,csize);
    return 0;

}

void read2d(int** ptr, int rsize, int csize)
{
    for(int i=0;i<rsize;i++)
    {
        for(int j=0;j<(csize-i);j++)
        {
            ptr[i][j] = i+j;
            printf("%d\t",ptr[i][j]);
        }
        printf("\n");
    }
}*/
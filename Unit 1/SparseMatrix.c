// a matrix for which most of the values are zero
// optimise space

// FAST TRANSPOSE
// triple notation: store only non-zero values along with their row and column numbers
// first row tells the size

#include<stdio.h>
#include<stdlib.h>
#include"SparseMatrix.h"

int main()
{
    term a[20];
    int n1,rno,cno,val;
    int rows, cols;
    printf("Enter rowsize, columnsize, number of non-zero values\n");
    scanf("%d",&rows);
    scanf("%d",&cols);
    scanf("%d",&val);

    // a[0] contains the total number of rows, columns and number of non zero values
    a[0].col = cols;
    a[0].row = rows;
    a[0].value = val;   // number of non-zero values
    int pos=1;
    for(int j=0;j<rows;j++)
    {
        for(int k=0;k<cols;k++)
        {
            scanf("%d",&val);
            if(val!=0)
            {   
                a[pos].col = k;
                a[pos].row = j;
                a[pos].value = val;
                pos++;
            }
        }
    }

    printf("Row  column  value\n");

    for(int p=0;p<val;p++)
    {
        printf("%d       %d      %d\n",a[p].row,a[p].col,a[p].value);
    }

    int no = 1;     // starts from 1st row
    printf("\nThe matrix is\n");
    for(int r=0;r<rows;r++)
    {
        for(int c=0;c<cols;c++)
        {
            if(a[no].row==r && a[no].col == c)
            {
                printf("%d\t",a[no].value);
                no++;
            }
            else
            {
                printf("0\t");
            }
        }
        printf("\n");
    }
    printf("\n");
    
    //printf("The tranposed matrix is\n");
    // to find transpose matrix, row and column are swapped. But now, row is not sorted.
    // after swapping, find number of (new) columns in each (new) row
    
    int *row_arr = (int*)calloc(val,sizeof(int));   
    for(int var=0;var<=val;var++)
    {
        int k = a[var].col;
        row_arr[k]++;
    }


    
    int *start_pos = (int*)calloc(cols,sizeof(int));
    start_pos[0] = 1;
    for(int f=1;f<cols;f++)
    {
        printf("%d\t",start_pos[f-1]);
        start_pos[f] = start_pos[f-1] + row_arr[f-1];
    }
    
    printf("Check2\n");

    term b[50];     // new row column value array
    b[0].row = cols;
    b[0].col = rows;
    b[0].value = val;
    for(int i=1;i<=val;i++)
    {
        b[start_pos[a[i].col]].row = a[i].col;
        b[start_pos[a[i].col]].col = a[i].row;
        b[start_pos[a[i].col]].value = a[i].value;
        start_pos[a[i].col]++;
    }

    no = 1;
    printf("\nThe transposed matrix is\n");
    for(int r=0;r<cols;r++)
    {
        for(int c=0;c<rows;c++)
        {
            if(b[no].row==r && b[no].col == c)
            {
                printf("%d\t",b[no].value);
                no++;
            }
            else
            {
                printf("0\t");
            }
        }
        printf("\n");
    }

    return 0;
}
// 2D array called ajdmat
// DFS traversal of graph using recursion

#include<stdio.h>
#define Max 10

void dfs(int adjmat[][Max], int visited[],int src,int n)
{   
    visited[src] = 1;
    printf("%d\t",src);
    for(int i=0;i<n;i++)
    {
        if(adjmat[src][i]==1 && visited[i]==0)  //unvisited neighbor in src row
        {
            dfs(adjmat,visited,i,n);
        }
    }
}


int main()
{
    int n;
    int adjmat[Max][Max];
    int visited[Max];
    printf("Number of vertices: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            scanf("%d",&adjmat[i][j]);
        visited[i] = 0;
    }
    int src=0;
    // start the traversal from src
    dfs(adjmat,visited,src,n);

    // to check if graph is connected. Won't be traversed through dfs 
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            printf("Graph is disconnected\n");
            exit(0);
        }
    }

    // to find how many units are in the graph. = number of dfs traversals required
    for(int i=0;i<n;i++)
        visited[i] = 0; // reset
    int count = 0;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            count++;
            dfs(adjmat,visited,i,n);

        }
    }
    return 0;

}


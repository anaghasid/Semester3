#include<stdlib.h>
#include<stdio.h>

/*edge list structure for each edge */
typedef struct{
    unsigned int first;
    unsigned int second;
    int visited;
}edge;


void dfs(edge* edges, unsigned int n, unsigned int first)
{
    for(int i=0;i<n;i++)
    {
        if(edges[i].visited==0 && edges[i].first==first)
        {
            printf("%d\t",first);
            edges[i].visited = 1;
            if(n>1 && (i+1)<n)
            dfs(i+1+edges,n-1,edges[i].second);
        }
        if(edges[i].visited==1)
            edges[i].visited = 2;
    }
}

unsigned int cycle_finder(const edge *edges , unsigned int n, unsigned int order)
{
    for(int i=0;i<n;i++)
    {
        if(edges[i].visited==2)
        {
            return 1;
        }
    }
    return 0;
}
/* DO NOTE THAT THE GRAPH TRAVERSAL IN THIS QUESTION ALWAYS STARTS WITH NODE 0  so you need not take any input for starting node */
int main(void)
{
    unsigned int order;  /* number of vertices */
    unsigned int n; /* number of edges */
    scanf("%d", &n);
    scanf("%d", &order);
    edge *edges;
    unsigned int ans;
    edges = malloc(n*sizeof(edge));
    if(edges==NULL)
    {
        return 1;
    }
    for(int i=0;i<n;++i)
    {
        edges[i].visited = 0;
        scanf("%d", &edges[i].first);
        scanf("%d", &edges[i].second);
    }
    
    dfs(edges,n,edges[0].first);
    
    ans= cycle_finder(edges, n, order);
    printf(ans? "cyclic":"acyclic");
    free(edges);
    
    return 0;

}
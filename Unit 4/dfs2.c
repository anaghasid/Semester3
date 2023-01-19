//	DFS traversal for a connected graph
//	Adjacency matrix representation

#include<stdio.h>
#define MAX 10

void createGraph(int adj[MAX][MAX],int n);
void dfs(int adj[MAX][MAX],int n,int visited[MAX],int src);

int main()
{
    int n,src;

    int adj[MAX][MAX]={0};
	int visited[MAX]={0};

    printf("Enter the no. of vertices\n");
	scanf("%d",&n);
	
	printf("Enter the adjacency information\n");
	createGraph(adj,n);
	
	printf("Enter the source vertex\n");
	scanf("%d",&src);
	
	printf("DFS traversal\n");
	dfs(adj,n,visited,src);
}

void createGraph(int adj[MAX][MAX],int n)
{
	int src,dest;
	printf("Enter -1 -1 to stop adding edges\n");
	while(1)
	{
		scanf("%d%d",&src,&dest);
		if(src<0 || dest<0 || src>=n || dest>=n )
			break;
		adj[src][dest]=1;
	}
}

void dfs(int adj[MAX][MAX],int n,int visited[MAX],int src)
{
    int s[MAX];		//create stack
	int top=-1;		//initialize stack
    // int parent[MAX];

    s[++top]=src;
	visited[src]=1;
	printf("%d ",src);

    int v;
	while(top!=-1)
    {
        v=s[top];		//Peek the stack
		int i;
		for(i=0;i<n;i++)
		{
			if(adj[v][i] && !visited[i]) //if an adj & unvisited vertex is found, start exploring that vertex
			 	break;
            if(adj[v][i] && visited[i])// && parent[i]!=v) //if an adj vertex is already visited 
				printf("Cycle is present");
		}
		
		if(i<n)
		{
			s[++top]=i;
			visited[i]=1;
			printf("%d ",i);
            // parent[i] = v;
		}
		else
			top--;
    }
}
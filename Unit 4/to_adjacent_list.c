#include<stdio.h>
#include<stdlib.h>


// REFER https://www.geeksforgeeks.org/graph-and-its-representations/
typedef struct gnode{
    int vertex;
    struct gnode *link;
}gnode;

typedef struct graph{
    int numbervertex;
    int *visited;
    gnode **adjlist;
}Graph;

void initgraph(Graph *graph,int n){
    graph->numbervertex=n;
    graph->visited=(int*)malloc(n*sizeof(int));
    printf("hi");
    graph->adjlist=(gnode**)malloc(n*sizeof(gnode*));
    for(int i=0;i<n;i++)
        graph->adjlist[i]=NULL;
    
}
void add_edge(Graph *graph,int src,int dest){
    gnode *temp=(gnode*)malloc(sizeof(gnode));
    temp->vertex=dest;
    temp->link=graph->adjlist[src];
    graph->adjlist[src]=temp;
    gnode *present=(gnode*)malloc(sizeof(gnode));
    present->vertex=src;
    present->link=graph->adjlist[dest];
    graph->adjlist[dest]=present;
}
void printgraph(Graph *graph){
    gnode *present=NULL;
    for(int i=0;i<graph->numbervertex;i++){
        present=graph->adjlist[i];
        printf("%d:",i);
        while (present!=NULL)
        {
            printf("%d ",present->vertex);
            present=present->link;
        }
        printf("\n");
}
}
int main(){
    int n,src,dest,numberedges;
    Graph graph;
    printf("Number of vertices:");
    scanf("%d",&n);
    initgraph(&graph,n);
    printf("Number of edges:");
    scanf("%d",&numberedges);
    for(int i=0;i<numberedges;i++){
        printf("src dest:");
        scanf("%d%d",&src,&dest);
        add_edge(&graph,src,dest);
    }
    printgraph(&graph);
}

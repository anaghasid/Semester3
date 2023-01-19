// find minimum distance between two nodes

#include <stdio.h>
#include <stdlib.h>
#define MAX_NODES 50
#define INFINITY 9999

typedef struct graph
{
    int n;                         /* Number of vertices in graph */
    int adj[MAX_NODES][MAX_NODES]; /* Adjacency matrix */
} Graph;

// creates the graph
void create_graph(Graph *adj_mat)
{

    int i, j;
    for (int i = 0; i < adj_mat->n; ++i)
    {
        for (int j = 0; j < adj_mat->n; ++j)
        {
            adj_mat->adj[i][j] = 0;
        }
    }
    while (1)
    {
        // edge between two vertex
        scanf("%d %d\n", &i, &j);
        if (i < 0 && j <= 0 || i >= adj_mat->n || j >= adj_mat->n)
        {
            break;
        }
        adj_mat->adj[i][j] = 1;
    }
}
// helper functions for inserting an element into a bfs_listeue
void append(int *bfs_listeue, int v, int *pqr)
{
    ++(*pqr);
    bfs_listeue[*pqr] = v;
}
// helper function to delete from a bfs_listeue
int delete (int *bfs_listeue, int *pqr)
{
    int res = bfs_listeue[0];
    for (int i = 0; i < *pqr; ++i)
    {
        bfs_listeue[i] = bfs_listeue[i + 1];
    }
    --(*pqr);
    return res;
}

void bfs(Graph *adj_mat, int source, int dest, int *prev_list)
{
    int bfs_list[adj_mat->n];
    for (int i = 0; i < (adj_mat->n); i++)
        bfs_list[i] = 0;
    int f = 0, r = -1;

    int visited[adj_mat->n];
    for (int i = 0; i < (adj_mat->n); i++)
        visited[i] = -1;

    r++;
    bfs_list[r] = source;
    visited[source] = 1;

    int x, i;
    while (f <= r)
    {
        x = bfs_list[f++];
        for (int i = 0; i < (adj_mat->n); i++)
        {
            if ((adj_mat->adj)[x][i] && (visited[i] == -1))
            {
                bfs_list[++r] = i;
                visited[i] = 1;
                // stores previous element that leads to the node
                prev_list[i] = x;
            }
        }
    }
}

// bfs function to calculate the minimum distance
int find_dist(Graph *adj_mat, int source, int dest)
{
    int prev_list[adj_mat->n];
    for (int i = 0; i < (adj_mat->n); i++)
        prev_list[i] = -1;

    bfs(adj_mat, source, dest, prev_list);

    int path[(adj_mat->n)];
    int l = 0;
    for (int i = dest; i != -1; i = prev_list[i])
        path[l++] = i;

    int temp;


    if (path[0] == source)
        return l - 1;

    return -1;
}

int main()
{
    Graph adj_mat;

    int source, dest;

    // number of vertex
    scanf("%d\n", &adj_mat.n);
    // creates adj matrix
    create_graph(&adj_mat);

    // source vertex
    scanf("%d\n", &source);

    // destination vertex
    scanf("%d", &dest);

    int result = find_dist(&adj_mat, source, dest);
    printf("%d", result);
    return 0;
}
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
// helper functions for inserting an element into a bfs_arrayeue
void append(int *bfs_arrayeue, int v, int *pqr)
{
    ++(*pqr);
    bfs_arrayeue[*pqr] = v;
}
// helper function to delete from a bfs_arrayeue
int delete (int *bfs_arrayeue, int *pqr)
{
    int res = bfs_arrayeue[0];
    for (int i = 0; i < *pqr; ++i)
    {
        bfs_arrayeue[i] = bfs_arrayeue[i + 1];
    }
    --(*pqr);
    return res;
}

void bfs(Graph *adj_mat, int source, int dest, int *prev)
{
    int bfs_array[adj_mat->n];
    // bfs_list is an array that stores all elements 

    for (int i = 0; i < (adj_mat->n); i++)
        bfs_array[i] = 0;
    int f = 0, r = -1;
    // f is the current location that loop is on. r is the current end of the array

    int visited[adj_mat->n];
    for (int i = 0; i < (adj_mat->n); i++)
        visited[i] = -99;

    bfs_array[++r] = source;
    visited[source] = 1;

    int x, i;
    while (f <= r)
    {
        x = bfs_array[f];
        f++;
        for (int i = 0; i < (adj_mat->n); i++)
        {
            if ((adj_mat->adj)[x][i] && (visited[i] == -99))
            {   
                bfs_array[++r] = i;
                visited[i] = 1;
                prev[i] = x;
            }
        }
    }
}

// bfs function to calculate the minimum distance
// You are rebfs_arrayired to complete this function
int find_dist(Graph *adj_mat, int source, int dest)
{

    int prev_list[adj_mat->n];
    for (int i = 0; i < (adj_mat->n); i++)
        prev[i] = -99;

    bfs(adj_mat, source, dest, prev);

    int path[(adj_mat->n)];
    int l = 0;
    for (int i = dest; i != -99; i = prev_list[i])
        path[l++] = i;

    int temp;

    if (path[l-1] == source)
        return l - 1;

    return -1;
}

int main()
{
    Graph adj_mat;

    int source, dest;

    // number of vertices
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
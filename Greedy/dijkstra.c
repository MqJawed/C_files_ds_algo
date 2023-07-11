#include<stdio.h>

#define INF 999

void dist(int n, int graph[n][n],int d[n],int source)
{
        
        for (int j = 0; j<n; j++) // IN array 'd' will assign the distance of each node from source initially
        {
            d[j] = graph[source][j];
        }
        d[source] = 0; //though there is no edge between source and source but the distance is marked 0
}

void relax(int n, int graph[n][n], int d[],int vertex) // Here, vertex is the node on which relaxation is to be performed
{
    for (int j = 0; j<n; j++)
    {
        if (graph[vertex][j] != INF) // If vertex is connected to the node
        {
            if(d[vertex] + graph[vertex][j] < d[j])  // distance of vertex from souce + distance of the node from vertex < distance of the node from source
            {
                d[j] = d[vertex] + graph[vertex][j]; // assign distance of vertex = distance of vertex from souce + distance of the node from vertex (see graph)
            }
        }
    }
}

void main()
{
    int n = 6;
    int graph[6][6] =              // REPRESENTATION OF GRAPH by ABDUL BARI
    {
        {INF,2,4,INF,INF,INF},                    
        {INF,INF,1,7,INF,INF},                              
        {INF,INF,INF,INF,3,INF},
        {INF,INF,INF,INF,INF,1},
        {INF,INF,INF,2,INF,5},
        {INF,INF,INF,INF,INF,INF}
    }; 
    int d[n];
    int source = 0;
    int vertex;
    dist(n, graph, d, source);
    
    int visited[6] = {0,0,0,0,0,0};
    visited[source] = 1;
 
    for (int count = 1; count <= n-1; count++)  // 5 vertex from source so 5 iteration
    {   
        int min = INF; 
        for (int j = 0; j<n; j++)  // for choosing shortest path from source
        {    
            if ((visited[j] != 1) && (d[j]<=min)) // If the node is not visited yet and having the shortest path
            {
                min = d[j];
                vertex = j;
            }
        }
        visited[vertex] = 1;  // mark the vertex visited 
        relax(n, graph, d,vertex); // performing relaxation on the vertex

        //Printing the result after relaxation of each vertex
        // for (int i = 0; i<n; i++)
        //     printf("%d\t",d[i]);
        // printf("\n");
    }
    // Printing the ultimate result
    for (int i = 0; i<n; i++)
    {
        printf("%d\t",d[i]);
    }
}
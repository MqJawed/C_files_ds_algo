#include<stdio.h>

#define INF 999

void dist(int n, int graph[n][n],int d[n],int source)
{
        
        for (int j = 0; j<n; j++) // IN array 'd' will assign the distance infinity
        {
            d[j] = INF;
        }
        d[source] = 0; // though there is no edge between source and source but the distance is marked 0
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

    for (int count = 1; count <= n-1; count++)  // total 6 vertex from source so 5 iteration
    {   
        for (int j = 0; j<n; j++)
        {    
        relax(n, graph, d,j); // performing relaxation on every vertex
        }
    }
    // Printing the ultimate result
    for (int i = 0; i<n; i++)
    {
        printf("%d\t",d[i]);
    }  
}
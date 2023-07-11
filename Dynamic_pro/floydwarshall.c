#include<stdio.h>

#define INF 999

void printmatrix(int n, int a[n][n])
{
    int i,j;
    for(i = 0; i<n; i++)
        {
            for(j = 0; j<n; j++)
            {   
                if (a[i][j] != INF)
                    printf("%d\t",a[i][j]);
                else
                    printf("INF\t");
            }
            printf("\n");
        }
}

void flwar(int n, int graph[n][n])
{
    int matrix[n][n],i,j,k;
    for(i = 0; i<n; i++)
        {
            for(j = 0; j<n; j++)
            {
                    matrix[i][j] = graph[i][j];
            }
        }
    for(k = 0; k<n; k++)
    {
        for(i = 0; i<n; i++)
        {
            for(j = 0; j<n; j++)
            {
                if (matrix[i][j] > matrix[i][k] + matrix[k][j])
                    
                    matrix[i][j] = matrix[i][k] + matrix[k][j];

            }
        } 
    }
    printmatrix(n,matrix);
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
    printmatrix(n,graph);
    printf("\n\n");
    flwar (6,graph);

}
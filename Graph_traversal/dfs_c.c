#include<stdio.h>
int a [7][7] =              // REPRESENSTATION OF GRAPH
    {
        {0,1,1,1,0,0,0},                    
        {1,0,1,0,0,0,0},                              //SCREENSHOT NO. 83
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0}, 
        {0,0,0,0,1,0,0}
    }; 
 int visited[7] = {0,0,0,0,0,0,0}; // Intially every node is marked unvisited
void dfs(int i) // create stack like binary tree height calculation
{   
    printf("%d ",i);
    visited[i] = 1;
    for (int j=0;j<7;j++)
    {
        if (a[i][j] == 1 && visited[j] == 0) // i, j both indicating vertex,a[i][j] is indicating where there is an edge or not 
            dfs(j);
    }
}
void main()
{
    dfs(4); // for understanding, create tree structure as height calculation of binary tree but after completing a total flow then come to another child
}
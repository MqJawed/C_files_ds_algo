#include<stdio.h>

// We will start from any arbitary node and add it to visited array and enqueue it to explore array.
// Now dequeue the enqueued node; Corr to that enqueued node all the attached node will be added to visisted array as well as enqueued it into explore array 
// iff they are not added previously to the visited array.
// repeat this till the explore array becomes empty

void enqueue(int a[], int * front, int *rear, int size, int data)
{
    if (*front ==-1 && *rear == -1) // is empty
    {
        *rear = *front = 0;
        a[*rear] = data;
    }
    else if (*rear == size-1)
        printf("full");
    else
    {
        *rear += 1;
        a[*rear] = data;
    }
}

int dequeue(int a[], int * front, int *rear)
{
    int ret;
    if (*front == -1 && *rear ==-1) // is empty
    {
        printf("empty");
    }
    else if (*rear == *front) // only 1 element
     {  
        ret = a[*front];
        *front = *rear = -1;
     }
    else
    {
        ret = a[*front];
        *front += 1;
    }
    return ret;
}

void main()
{
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

    int front = -1;
    int rear = -1;

    int i=0;  // starting node
    int visited[7] = {0,0,0,0,0,0,0}; // Intially every node is marked unvisited 
    int explore[7];
    printf("%d ",i);
    visited[0] = 1; // the visited nodes are marked by 1
    enqueue(explore, &front, &rear, 7, i);
    while (front != -1 && rear != -1) // isempty condition
    {   //printf("dak");
        int p = dequeue(explore, &front, &rear);
        for (int j=0; j<7; j++)
        {
            if (a[p][j] == 1 && visited[j]==0)  // if the dequeued element has any connection and and that connection has not been visited
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(explore, &front, &rear,7,j);
            }
        }
    }
     
}
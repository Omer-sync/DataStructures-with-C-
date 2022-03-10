#include<stdio.h>

#define N 12

int visited[N] = {0};
int adjacencyMatrix[N][N] = {0};
int path[N] = {0};
int element = 1;
int control = 0;
char nodes[N] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H','I','J','K','L'};

// Making adjacency matrix with given edges
void adjacencyMatrix_maker(int Matrix[N][N]);
// Finding a path with given 2 terminal points
void DFS( int index,int key);
// Displaying solution path
void printSolution(int A[N]);
// Displaying node names
void printNodes(char A[N]);






int main()
{
    int a  = 0;
    int b  = 0;
    adjacencyMatrix_maker(adjacencyMatrix);

    printf("\nRECURSIVE DEPTH-FIRST SEARCH METHOD\n");
    printNodes(nodes);

    printf("Enter numbers of Starting and Ending nodes : ");
    scanf("%d %d",&a,&b);

    path[0] = a-1;

    DFS(a-1,b-1);
    printSolution(path);
    return 0;
}
// Making adjacency matrix with given edges
void adjacencyMatrix_maker(int Matrix[N][N])
{
    int edges[21][2] = { {0,1},{0,9},{0,10},{1,8},{2,3},{3,5},{4,0},
                         {4,2},{5,7},{5,11},{6,1},{6,7},{7,3},{8,5},
                         {8,10},{9,2},{9,3},{10,4},{10,6},{11,6},{11,8} };
    int i;
    for ( i = 0; i < 21; i++)
        Matrix[edges[i][0]][edges[i][1]] = 1 ;    
}

// Finding a path with given 2 terminal points
void DFS( int index,int key)
{
    int i;
    visited[index] = 1;
    // When it reach end point
    if (index == key)
    {
        path[element] = -1;
        control = -1;
        return ;
    }
    // While it is walking on the graph
    for ( i = 0; i < N; i++)
    {
        if (adjacencyMatrix[index][i] != 0 && visited[i] != 1 && control != -1)
        {              
            path[element] = i;
            element++;
            DFS(i,key);
        }
    }
    // When it is obvious that there is no more right node to walk, it goes back to search the right node
    if (i == N && control != -1)
    {
        element--;
        DFS(path[element-1],key);
    }
}
// Displaying solution path
void printSolution(int A[N])
{
    int i;
    printf("\nSOLUTION PATH =\n");
    for(i=0;A[i+1] != -1 ;i++)
        printf("%c   ",nodes[A[i]]);
            
    printf("%c ",nodes[A[i]]);
}
// Displaying node names
void printNodes(char A[N])
{
    int i;
    printf("\nNODES IN DIRECTED GRAPH:\n");

    for(i=0; i<N ;i++)
        printf("%d. %c\n",i+1,nodes[i]);
}


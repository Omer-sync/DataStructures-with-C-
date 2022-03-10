// This code gives the least connected node with the given adjacencyMatrix
#include<stdio.h>

#define N 7

int visited[N] = {0};
int adjacencyMatrix[N][N] = {0};
int path[N] = {0};
int element = 1;
int control = 0;
char nodes[N] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};

// Making adjacency matrix with given edges
void adjacencyMatrix_maker(int Matrix[N][N]);
void printMatrix(int A[N][N]);
char Find_Least_Connected(int graf[N][N]);


int main()
{
    int a ;
    int b ;
    adjacencyMatrix_maker(adjacencyMatrix);
    //printMatrix(adjacencyMatrix);
    printf("%c",Find_Least_Connected(adjacencyMatrix));
    
    return 0;
}
// Making adjacency matrix with given edges
void adjacencyMatrix_maker(int Matrix[N][N])
{
    int edges[21][2] = { {0,1},{0,3},{0,6},{1,0},{3,0},{6,0},{1,2},
                         {1,6},{2,1},{6,1},{2,5},{2,6},{5,2},
                         {6,2},{3,4},{4,3},{4,5},{4,6},{5,4},{6,4} };
    int i;
    for ( i = 0; i < 21; i++)
        Matrix[edges[i][0]][edges[i][1]] = 1 ;    
    Matrix[0][0] = 0;
}
char Find_Least_Connected(int graf[7][7])
{
    char min = nodes[0];
    int i,j;
    int count = 0;
    int firstrow = 0;
    for ( i = 0; i < N; i++)
    {
        if (graf[0][i] == 1)
            firstrow++;
    }
    for ( i = 1; i < N; i++)
    {
        for ( j = 0; j < N; j++)
        {
            if (graf[i][j] == 1)
                count++;
        }
        if (count < firstrow)
            min = nodes[i];
    }
    return min;
}
void printMatrix(int A[N][N])
{
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            printf("%d\t",A[i][j]);
        
        printf("\n");
    } 
}


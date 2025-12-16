#include <stdio.h>

int a[4][4];
int visited[4];
int r = 4;
void DFS(int i)
{
    visited[i] = 1; //mark as visited and print
    printf("%c ", i + 65);

    for (int j = 0; j < r; j++)  //span across column, same row
    {
        if (a[i][j] == 1 && visited[j] == 0) //if connected and not visited 
        {
            DFS(j);
        }
    }
}

void BFS(int start)
{
    int queue[10];
    int front = 0, rear = 0;
    // mark start as visited and enqueue
    visited[start] = 1;
    queue[rear++] = start; 

    while (front < rear) //traverse queue till empty
    {
        int i = queue[front++]; //store value before dequeue
        printf("%c ",i + 65); //print front

        for (int j = 0; j < r; j++)
        {
            if (a[i][j] == 1 && visited[j] == 0) //if edge existed and not visited, mark as visited and add to queue
            {
                visited[j] = 1;
                queue[rear++] = j;
            }
        }
    }
}

void main()
{
    int i, j;

    // Input adjacency matrix
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < r; j++)
        {
            printf("Input element %d,%d: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nDFS Traversal:\n");
    for (i = 0; i < r; i++)
        visited[i] = 0;
    DFS(0);

    printf("\n\nBFS Traversal:\n");
    for (i = 0; i < r; i++)
        visited[i] = 0;
    BFS(0);

    printf("\n");
}

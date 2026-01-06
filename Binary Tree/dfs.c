#include <stdio.h>

int a[4][4];
int visited[4];
int r = 4;

/* DFS FUNCTION */
void DFS(int i)
{
    visited[i] = 1;
    printf("%c ", i + 65);

    for(int j = 0; j < r; j++)
    {
        if(a[i][j] == 1 && visited[j] == 0)
        {
            DFS(j);
        }
    }
}

/* GLOBAL QUEUE FOR BFS */
int queue[10];
int front = 0, rear = -1;

/* BFS USING RECURSION */
void BFS(int i)
{
    printf("%c ", i + 65);

    for(int j = 0; j < r; j++)
    {
        if(a[i][j] == 1 && visited[j] == 0)
        {
            visited[j] = 1;
            queue[++rear] = j;
        }
    }

    if(front <= rear)
        BFS(queue[front++]);
}

void main()
{
    int i, j;

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < r; j++)
        {
            printf("Input element %d,%d: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nDFS Traversal:\n");
    for(i = 0; i < r; i++)
        visited[i] = 0;

    DFS(0);

    printf("\n\nBFS Traversal:\n");
    for(i = 0; i < r; i++)
        visited[i] = 0;

    front = 0;
    rear = -1;

    visited[0] = 1;
    queue[++rear] = 0;
    BFS(queue[front++]);

    printf("\n");
}

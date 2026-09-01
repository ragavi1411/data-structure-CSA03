#include <stdio.h>

int main()
{
    int graph[10][10], visited[10] = {0};
    int queue[10], front = 0, rear = 0;
    int n, start, i, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
        for(v = 0; v < n; v++)
            scanf("%d", &graph[i][v]);

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS Traversal: ");

    while(front < rear)
    {
        v = queue[front++];
        printf("%d ", v);

        for(i = 0; i < n; i++)
        {
            if(graph[v][i] == 1 && visited[i] == 0)
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }

    return 0;
}

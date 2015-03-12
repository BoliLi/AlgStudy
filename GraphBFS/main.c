#include <stdio.h>
#include <stdlib.h>
#include "../LBLsContainer/LBLsContainer.h"

#define MAXVEX 6
#define INFINITY 32767
#define NO_EXIST -1

void graph_bfs(int graph[MAXVEX][MAXVEX], int start_point)
{
    static int visited[MAXVEX] = {0};
    int points[MAXVEX];
    int i = 0;
    int cur_point;
    queue q;

    for(i = 0; i < MAXVEX; i++)
    {
        points[i] = i;
    }

    queue_init(&q, sizeof(int) * MAXVEX, MAXVEX);

    visited[start_point] = 1;
    printf("%d ->\n", start_point);
    /*起始点入队*/
    enqueue(&q, (void *)&points[start_point], sizeof(int));

    /*如果队列非空*/
    while(q.head != q.tail)
    {
        dequeue(&q, &cur_point, sizeof(int));

        for(i = 0; i < MAXVEX; i++)
        {
            if(graph[cur_point][i] != INFINITY && visited[i] == 0)
            {
                visited[i] = 1;
                printf("%d ->\n", i);
                enqueue(&q, (void *)&points[i], sizeof(int));
            }
        }
    }
}

int main()
{
    int graph[MAXVEX][MAXVEX];
    int i, j;
    FILE *file;

    file = fopen("data.txt", "r+");
    if(NULL == file)
    {
        printf("File does not exist.");
        return 0;
    }

    j = 0;
    while(!feof(file))
    {
        for(i = 0; i < MAXVEX; i++)
        {
            fscanf(file, "%d ", &graph[j][i]);
        }
        j++;
    }
    printf("Original sequence:\n");
    for(i = 0; i < MAXVEX; i++)
    {
        for(j = 0; j < MAXVEX; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
    graph_bfs(graph, 0);

    fclose(file);
    return 0;
}

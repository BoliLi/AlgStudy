#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 6
#define INFINITY 32767
#define NO_EXIST -1

void graph_dfs(int graph[MAXVEX][MAXVEX], int cur_point)
{
    static int visited[MAXVEX] = {0};
    int i = 0;

    visited[cur_point] = 1;
    printf("%d -> ", cur_point);
    /*访问下一个没访问过的点*/
    while(i < MAXVEX)
    {
        if(graph[cur_point][i] != INFINITY && visited[i] == 0)
        {
            graph_dfs(graph, i);
        }
        i++;
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
    graph_dfs(graph, 5);

    fclose(file);
    return 0;
}

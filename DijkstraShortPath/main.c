#include <stdio.h>
#include <stdlib.h>

#define MAXVEX 6
#define INFINITY 32767
#define NOT_EXIST -1

void dijkstra_shortpath(int graph[MAXVEX][MAXVEX], int dist[MAXVEX], int path[MAXVEX], int start_point, int end_point)
{
    int close_list[MAXVEX] = {0};
    int open_list[MAXVEX] = {0};
    int open_cnt = 0, close_cnt = 0;
    int shortest_dist, cur_point = start_point;
    int i;

    for(i = 0; i < MAXVEX; i++)
    {
        path[i] = NOT_EXIST;
    }

    /*初始化，记录从起始点出来的所有节点加入open list*/
    for(i = 0; i < MAXVEX; i++)
    {
        dist[i] = graph[start_point][i];
        if(dist[i] < INFINITY)
        {
            printf("1 path[%d] = %d\n", i, path[i]);
            path[i] = start_point;
            printf("2 path[%d] = %d\n", i, path[i]);
            open_list[i] = 1;
            open_cnt++;
        }
    }

    /*将初始节点加入close list*/
    close_list[start_point] = 1;
    close_cnt = 1;

    /*open list为空表示不存在要找的路径，当目标节点被加入close list时表示最短路径找到*/
    while(open_cnt > 0 && cur_point != end_point)
    {
        shortest_dist = INFINITY;

        /*从open list中找出当前已知路径中的最短路径*/
        for(i = 0; i < MAXVEX; i++)
        {
            if(open_list[i] == 1 && shortest_dist > dist[i])
            {
                shortest_dist = dist[i];
                cur_point = i;
            }
        }
        /*将当前节点移除open list，加入close list*/
        open_list[cur_point] = 0;
        open_cnt--;
        close_list[cur_point] = 1;
        close_cnt++;

        /*计算从起始点，经过当前节点，到下一节点的距离，如果有更短路径则更新dist列表
        如果该下一节点在close list里则忽略，否则加入open list*/
        for(i = 0; i < MAXVEX; i++)
        {
            if(close_list[i] == 0 && graph[cur_point][i] < INFINITY)
            {
                if(dist[i] > dist[cur_point] + graph[cur_point][i])
                {
                    dist[i] = dist[cur_point] + graph[cur_point][i];
                    printf("1 path[%d] = %d\n", i, path[i]);
                    path[i] = cur_point;
                    printf("2 path[%d] = %d\n", i, path[i]);
                }
                /*防止重复加入*/
                if(open_list[i] == 0)
                {
                    open_list[i] = 1;
                    open_cnt++;
                }
            }
        }
    }

    /*打印结果*/
    if(path[end_point] == NOT_EXIST)
    {
        printf("No path!\n");
        return;
    }

    printf("%d <= ", end_point);
    cur_point = end_point;
    while(path[cur_point] != start_point)
    {
        printf("%d <= ", path[cur_point]);
        cur_point = path[cur_point];
    }
    printf("%d", start_point);
}

int main()
{
    int graph[MAXVEX][MAXVEX], dist[MAXVEX] = {0}, path[MAXVEX] = {NOT_EXIST};
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
    dijkstra_shortpath(graph, dist, path, 0, 5);

    fclose(file);
    return 0;
}

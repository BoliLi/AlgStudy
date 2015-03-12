#include <stdio.h>
#include <stdlib.h>
#include "../LBLsContainer/LBLsContainer.h"

#define MAXVEX 6
#define MAXEDGE ((MAXVEX*(MAXVEX - 1))/2)
#define INFINITY 32767

typedef struct EdgeInfo
{
    int node1;
    int node2;
    int weight;
}EdgeInfo;

/*（1）首先将G的n个顶点看成n个孤立的连通分支。将所有的边按权从小大排序。*/
/*（2）从第一条边开始，依边权递增的顺序检查每一条边。
并按照下述方法连接两个不同的连通分支：当查看到第k条边(v,w)时，
如果端点v和w分别是当前两个不同的连通分支T1和T2的端点是，就用边(v,w)将T1和T2连接成一个连通分支，
然后继续查看第k+1条边；如果端点v和w在当前的同一个连通分支中，就直接再查看k+1条边。
这个过程一个进行到只剩下一个连通分支时为止。*/

int seek_in_set(int set[MAXVEX], int node)
{
    int i = node;
    while(set[i] != -1)
    {
        i = set[i];
    }
    return i;
}

void kruskal(int graph[MAXVEX][MAXVEX])
{
    int i, j;
    int edge_cnt;
    int parent1, parent2;
    int set[MAXVEX] = {0};
    QuickSortElem edges[MAXEDGE];
    EdgeInfo *edge_info;

    /*获取边信息*/
    edge_cnt = 0;
    for(i = 0; i < MAXVEX; i++)
    {
        for(j = i + 1; j < MAXVEX; j++)
        {
            if(graph[i][j] < INFINITY)
            {
                edges[edge_cnt].key = graph[i][j];
                edge_info = (EdgeInfo *)malloc(sizeof(EdgeInfo));
                edge_info->node1 = i;
                edge_info->node2 = j;
                edge_info->weight = graph[i][j];
                edges[edge_cnt].data = (void *)edge_info;
                edge_cnt++;
            }
        }
    }

    /*将这些边按权重由小到大排序*/
    quick_sort(edges, 0, edge_cnt - 1);

    /*初始化连通集合，set[i]=-1表示集合内只有i一个顶点，set[i]=j表示顶点i和j属于同一个集合且j是i的父节点*/
    for(i = 0; i < MAXVEX; i++)
    {
        set[i] = -1;
    }

    i = 0;
    j = 0;
    while(i < edge_cnt && j < MAXVEX - 1)
    {
        edge_info = (EdgeInfo *)edges[i].data;
        parent1 = seek_in_set(set, edge_info->node1);
        parent2 = seek_in_set(set, edge_info->node2);
        /*若不属于同一个集合则将两集合合并*/
        if(parent1 != parent2)
        {
            set[edge_info->node1] = edge_info->node2;
            j++;
            printf("%d -> %d  w: %d\n", edge_info->node1, edge_info->node2, edge_info->weight);
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
    kruskal(graph);

    fclose(file);
    return 0;
}

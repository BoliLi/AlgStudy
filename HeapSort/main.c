#include <stdio.h>
#include <stdlib.h>

#define HEAP_SIZE 15

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void build_heap(int *data, int parent, int heap_size)
{
    int cur_child = 2 * parent + 1;
    int cur_parent = parent;

    while(cur_child < heap_size)
    {
        /*如果右儿子比较小则用右儿子与双亲比较*/
        if(cur_child < heap_size && data[cur_child] > data[cur_child + 1])
        {
            cur_child++;
        }
        /*如果最小的儿子比双亲大则交换两者，并比较新的儿子与儿子的儿子的大小*/
        if(data[cur_parent] > data[cur_child])
        {
            swap(&data[cur_child], &data[cur_parent]);
            cur_parent = cur_child;
            cur_child = 2 * cur_parent + 1;
        }
        else
        {
            cur_child = heap_size + 1;
        }
    }
}
int main()
{
    FILE *file;
    int data[HEAP_SIZE];
    int result[HEAP_SIZE];
    int i, j, tmp;

    file = fopen("data.txt", "r+");
    if(NULL == file)
    {
        printf("File does not exist.");
        return 0;
    }

    i = 0;
    while(!feof(file))
    {
        fscanf(file, "%d ", &data[i++]);
    }
    printf("Original sequence:\n");
    for(i = 0; i < HEAP_SIZE; i++)
    {
        printf("%d ", data[i]);
    }
    /*建立初始堆*/
    for(i = HEAP_SIZE / 2; i >= 0; i--)
    {
        build_heap(data, i, HEAP_SIZE);
    }

    j = 0;
    /*每次将堆顶取出，将堆末尾节点置顶*/
    for(i = HEAP_SIZE - 1; i >= 0; i--)
    {
        result[j++] = data[0];
        data[0] = data[i];
        build_heap(data, 0, i);
    }

    printf("\nSorted sequence:\n");
    for(i = 0; i < HEAP_SIZE; i++)
    {
        printf("%d ", result[i]);
    }
    fclose(file);
    return 0;
}

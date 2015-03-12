#include <stdio.h>
#include <stdlib.h>
#include "../LBLsContainer/LBLsContainer.h"

int main()
{
    FILE *file;
    QuickSortElem data[10];
    int i, j, tmp;
    int *p;

    file = fopen("data.txt", "r+");
    if(NULL == file)
    {
        printf("File does not exist.");
        return 0;
    }

    i = 0;
    while(!feof(file))
    {
        fscanf(file, "%d ", &data[i].key);
        p = (int *)malloc(sizeof(int));
        *p = data[i].key;
        data[i].data = (void *)p;
        i++;
    }
    printf("Original sequence:\n");
    for(i = 0; i < 10; i++)
    {
        p = (int *)data[i].data;
        printf("%d ", *p);
    }
    quick_sort(data, 0, 9);
    printf("\nSorted sequence:\n");
    for(i = 0; i < 10; i++)
    {
        p = (int *)data[i].data;
        printf("%d ", *p);
    }
    fclose(file);
    return 0;
}

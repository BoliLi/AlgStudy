#include <stdio.h>
#include <stdlib.h>

void merge_array(int data[], int head, int mid, int tail, int tmp[])
{
    int i = head;
    int j = 0;
    int k = mid + 1;

    while(i <= mid && k <= tail)
    {
        if(data[i] < data[k])
        {
            tmp[j++] = data[i++];
        }
        else
        {
            tmp[j++] = data[k++];
        }
    }
    while(i <= mid)
    {
        tmp[j++] = data[i++];
    }
    while(k <= tail)
    {
        tmp[j++] = data[k++];
    }
    for(i = 0; i < j; i++)
    {
        data[head + i] = tmp[i];
    }
}

void merge_sort(int data[], int head, int tail, int tmp[])
{
    if(head < tail)
    {
        int mid = (head + tail)/2;
        merge_sort(data, head, mid, tmp);
        merge_sort(data, mid + 1, tail, tmp);
        merge_array(data, head, mid, tail, tmp);
    }
}

int main()
{
    FILE *file;
    int data[10];
    int tmp[10];
    int i, j;

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
    for(i = 0; i < 10; i++)
    {
        printf("%d ", data[i]);
    }
    merge_sort(data, 0, 9, tmp);
    printf("\nSorted sequence:\n");
    for(i = 0; i < 10; i++)
    {
        printf("%d ", data[i]);
    }
    fclose(file);
    return 0;
}

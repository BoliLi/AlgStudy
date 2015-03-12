#include <stdio.h>
#include <stdlib.h>

void quick_sort(int *data, int head, int tail)
{
    int base = data[head];
    int tmp;
    int i = head;
    int j = tail;
    if(head < tail)
    {
        do
        {
            while((i < j)&&(data[j] > base))
            {
                j--;
            }
            if(i < j)
            {
                data[i] = data[j];
                i++;
            }
            while((i < j)&&data[i] < base)
            {
                i++;
            }
            if(i < j)
            {
                data[j] = data[i];
                j--;
            }
        }while(i < j);

        data[i] = base;
        quick_sort(data, head, i-1);
        quick_sort(data, i+1, tail);
    }
}

int main()
{
    FILE *file;
    int data[10];
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
    for(i = 0; i < 10; i++)
    {
        printf("%d ", data[i]);
    }
    quick_sort(data, 0, 9);
    printf("\nSorted sequence:\n");
    for(i = 0; i < 10; i++)
    {
        printf("%d ", data[i]);
    }
    fclose(file);
    return 0;
}

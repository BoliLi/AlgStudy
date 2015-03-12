#include <stdio.h>
#include <stdlib.h>

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
    for(i = 0; i < 10; i++)
    {
        for(j = 9; j > i; j--)
        {
            if(data[j] < data[j-1])
            {
                tmp = data[j];
                data[j] = data[j-1];
                data[j-1] = tmp;
            }
        }
    }
    printf("\nSorted sequence:\n");
    for(i = 0; i < 10; i++)
    {
        printf("%d ", data[i]);
    }
    fclose(file);
    return 0;
}

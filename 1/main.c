#include <stdio.h>
#include <stdlib.h>
//把一个字符串的大写字母放到字符串的后面，各个字符的相对位置不变，不能申请额外的空间。
int is_uppercase(char data)
{
    if(data >= 'A' && data <= 'Z')
    {
        return 1;
    }
    return 0;
}
void my_sort(char *data, int head, int tail)
{
    int i, j;
    int uppercase_count = 0;
    char tmp;

    for(i = tail; i >= head; i--)
    {
        if(is_uppercase(data[i]))
        {
            for(j = i; j < tail - uppercase_count; j++)
            {
                tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
            }
            uppercase_count++;
        }
    }
}

int main()
{
    FILE *file;
    char data[10];
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
        fscanf(file, "%c ", &data[i++]);
    }
    printf("Original sequence:\n");
    for(i = 0; i < 10; i++)
    {
        printf("%c ", data[i]);
    }
    my_sort(data, 0, 9);
    printf("\nSorted sequence:\n");
    for(i = 0; i < 10; i++)
    {
        printf("%c ", data[i]);
    }
    fclose(file);
    return 0;
}

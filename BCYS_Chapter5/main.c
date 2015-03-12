#include <stdio.h>
#include <stdlib.h>
#include "../LBLsContainer/LBLsContainer.h"

/*输入一个数组和一个数字，在数组中查找两个数，使得它们的和正好是输入的那个数
字。
要求时间复杂度是 O(n)。如果有多对数字的和等于输入的数字，输出任意一对即可。
例如输入数组 1、2、4、7、11、15 和数字 15。由于 4+11=15，因此输出 4 和 11。*/
int find_sum(int *data, int data_size, int sum)
{
    HashTable *hash_table;
    HashElement *hash_elem;
    int i, j;
    int *ai;
    int bi;
    int half_cnt;

    /*ai为数组中第i个元素，bi=sum-ai，哈希表存储bi和ai的映射关系*/
    hash_table = hash_table_init(data_size);

    for(i = 0; i < data_size; i++)
    {
        ai = (int *)malloc(sizeof(int));
        *ai = data[i];
        bi = sum - data[i];
        hash_elem = (HashElement *)malloc(sizeof(HashElement));
        hash_elem->data = (void *)ai;
        hash_elem->key = bi;
        hash_elem->next = NULL;
        hash_elem->value = bi;
        hash_insert(hash_table, data_size, hash_elem);
    }

    for(i = 0; i < data_size; i++)
    {
        ai = (int *)hash_find(hash_table, data_size, data[i], data[i]);
        if(ai != NULL)
        {
            if(*ai * 2 != sum)
            {
                printf("Found!\n%d + %d = %d", data[i], *ai, sum);
                return 0;
            }
            else
            {
                /*处理ai*2=sum的情况，因哈希表可能过滤掉重复的元素，因此需要遍历数组，若有两个ai满足ai*2=sum则找到答案*/
                half_cnt = 1;
                for(j = 0; j < data_size; j++)
                {
                    if(data[j] == *ai)
                    {
                        if(half_cnt == 2)
                        {
                            printf("Found!\n%d + %d = %d", *ai, *ai, sum);
                            return 0;
                        }
                        else
                        {
                            half_cnt++;
                        }
                    }
                }
            }
        }
    }
    return -1;
}

int main()
{
    FILE *file;
    int data[10];
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
    fclose(file);

    printf("Original sequence:\n");
    for(i = 0; i < 10; i++)
    {
        printf("%d ", data[i]);
    }
    printf("\n");
    find_sum(data, 10, 16);
    return 0;
}

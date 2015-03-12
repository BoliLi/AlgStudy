#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../LBLsContainer/LBLsContainer.h"

typedef struct
{
    char str[50];
    int cnt;
}word_info;

void swap_word_info(word_info *a, word_info *b)
{
    word_info tmp;
    int info_size = sizeof(word_info);

    memcpy(&tmp, a, info_size);
    memcpy(a, b, info_size);
    memcpy(b, &tmp, info_size);
}

void make_data()
{
    FILE *file;
    int i;
    int max_ele = 100;

    srand(time(0));

    file = fopen("data.txt", "w+");
    if(NULL == file)
    {
        printf("File does not exist.");
        return;
    }
    fprintf(file, "%d\n", max_ele);
    for(i = 0; i < max_ele; i++)
    {
        fprintf(file, "%d ", rand() % 100);
        if((i + 1) % 8 == 0)
        {
            fprintf(file, "\n");
        }
    }
    fclose(file);
}

/*建立小根堆*/
void min_heap(word_info *data, int parent, int heap_size)
{
    int cur_child = 2 * parent + 1;
    int cur_parent = parent;

    while(cur_child < heap_size)
    {
        /*如果右儿子比较小则用右儿子与双亲比较*/
        if(cur_child + 1 < heap_size && data[cur_child].cnt > data[cur_child + 1].cnt)
        {
            cur_child++;
        }
        /*如果最小的儿子比双亲小则交换两者，并比较新的儿子与儿子的儿子的大小*/
        if(data[cur_parent].cnt > data[cur_child].cnt)
        {
            swap_word_info(&data[cur_child], &data[cur_parent]);
            cur_parent = cur_child;
            cur_child = 2 * cur_parent + 1;
        }
        else
        {
            cur_child = heap_size + 1;
        }
    }
}


int heap_find_k_largest(word_info *data, int data_size, int k)
{
    FILE *file;
    int heap_size = k;
    word_info *heap;
    int i, j;

    heap = (word_info *)malloc(heap_size * sizeof(word_info));

    for(i = 0; i < heap_size; i++)
    {
        heap[i].cnt = data[i].cnt;
        strcpy(heap[i].str, data[i].str);
    }

    /*建立初始小根堆*/
    for(i = heap_size / 2; i >= 0; i--)
    {
        min_heap(heap, i, heap_size);
    }

    /*如果第j个元素比堆顶大则将其与堆顶元素交换，然后重新调整堆*/
    for(j = k; j < data_size; j++)
    {
        if(data[j].cnt > heap[0].cnt)
        {
            heap[0].cnt = data[j].cnt;
            strcpy(heap[0].str, data[j].str);
            min_heap(heap, 0, heap_size);
        }
    }

    file = fopen("result.txt", "w+");
    if(NULL == file)
    {
        printf("File does not exist.");
        return;
    }

    for(i = 0; i < heap_size; i++)
    {
        fprintf(file, "%s %d\n", heap[i].str, heap[i].cnt);
    }
    fprintf(file, "\n%d largest number:\n", k);
    for(i = 0; i < data_size; i++)
    {
        fprintf(file, "%s %d\n", data[i].str, data[i].cnt);
    }

    fclose(file);
    return 0;
}
unsigned int hash_str(char *str)
{
    unsigned int value = 0;
    int lower_char;

    while (*str != '\0')
    {
        lower_char = tolower(*str);
        value = value * 31 + lower_char;
        str++;
    }
    return value;
}

int handle_symbol(char *str, int len)
{
    int i = len - 1;
    int j;

    while(i >= 0)
    {
        if((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'z') ||
           (str[i] >= 'A' && str[i] <= 'Z') || str[i] == '\'')
        {
            i--;
        }
        else
        {
            str[i--] = '\0';
        }
    }

    i = 0;
    while(str[i] == '\0')
    {
        i++;
    }

    if(i > 0)
    {
        j = 0;;
        while(str[i] != '\0')
        {
            str[j++] = str[i++];
        }
        str[j] = '\0';
    }
    return 0;
}

int main()
{
    FILE *file;
    int *data;
    int data_size = 0;
    int i, j;
    word_info *word;
    word_info words[200];
    char str[50];
    int hash_table_size = 200;
    int hash_value;
    int str_len;
    HashTable *hash_table = NULL;
    HashElement *hash_elem;

#if 0
#if 1
    file = fopen("data.txt", "r+");
    if(NULL == file)
    {
        printf("File does not exist.");
        return 0;
    }

    fscanf(file, "%d\n", &data_size);
    data = (int *)malloc(data_size * sizeof(int));

    i = 0;
    while(!feof(file))
    {
        fscanf(file, "%d ", &data[i++]);
    }

    printf("Original sequence:\n");
    for(i = 0; i < data_size; i++)
    {
        printf("%d ", data[i]);
    }

    heap_find_k_largest(data, data_size, 5);
    fclose(file);
#else
    make_data();
#endif
#endif
    hash_table = hash_table_init(hash_table_size);
    if(NULL == hash_table)
    {
        printf("error\n");
        return 0;
    }

    file = fopen("string_data.txt", "r+");
    if(NULL == file)
    {
        printf("File does not exist.");
        return 0;
    }
    while(!feof(file))
    {
        fscanf(file, "%s", str);
        str_len = strlen(str);
        handle_symbol(str, str_len);
        hash_value = hash_str(str);
        word = (word_info *)hash_find(hash_table, hash_table_size, hash_value, hash_value);
        if(NULL == word)
        {
            word = (word_info *)malloc(sizeof(word_info));
            word->cnt = 1;
            strcpy(word->str, str);
            hash_elem = (HashElement *)malloc(sizeof(HashElement));
            hash_elem->data = (void *)word;
            hash_elem->key = hash_value;
            hash_elem->value = hash_value;
            hash_elem->next = NULL;
            hash_insert(hash_table, hash_table_size, hash_elem);
        }
        else
        {
            word->cnt++;
        }
    }
    fclose(file);

    /*遍历整个哈希表，将出现的词及出现次数存进words数组*/
    j = 0;
    for(i = 0; i < hash_table_size; i++)
    {
        hash_elem = hash_table[i].next;
        while(hash_elem != NULL)
        {
            word = (word_info *)hash_elem->data;
            words[j].cnt = word->cnt;
            strcpy(words[j++].str, word->str);
            hash_elem = hash_elem->next;
        }
    }

    heap_find_k_largest(words, j, 5);


    return 0;
}

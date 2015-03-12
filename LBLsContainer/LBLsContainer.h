#ifndef LBLSCONTAINER_H_INCLUDED
#define LBLSCONTAINER_H_INCLUDED
typedef struct
{
    void * data;
    int max_element;
    int head;
    int tail;
}queue;

typedef struct
{
    void * data;
    int max_element;
    int top;
    int bottom;
}stack;

typedef struct HashElement
{
    struct HashElement *next;
    int key;
    void * data;
    int value;
}HashElement;

typedef struct HashTable
{
    HashElement *next;
}HashTable;

typedef struct QuickSortElem
{
    int key;
    void * data;
}QuickSortElem;

int queue_init(queue *fifo, int len, int max_element);
int enqueue(queue *fifo, void *data, int element_size);
int dequeue(queue *fifo, void *data, int element_size);

int stack_init(stack *filo, int len, int max_element);
int stack_push(stack *filo, void *data, int element_size);
int stack_pop(stack *filo, void *data, int element_size);

HashTable * hash_table_init(int table_size);
void * hash_find(HashTable hash_table[], int table_size, int key, int value);
int hash_insert(HashTable hash_table[], int table_size, HashElement *element);

void quick_sort(QuickSortElem *data, int head, int tail);

void get_next(const char *sub_str, int sub_str_cnt, int *next);
int kmp_str_search(const char *main_str, const char *sub_str, int main_str_cnt, int sub_str_cnt);

#endif // LBLSCONTAINER_H_INCLUDED

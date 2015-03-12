#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*定义字符串的左旋转操作：把字符串前面的若干个字符移动到字符串的尾部。
如把字符串 abcdef 左旋转 2 位得到字符串 cdefab。
请实现字符串左旋转的函数，要求对长度为 n 的字符串操作的时间复杂度为
O(n)，空间复杂度为 O(1)。*/

void reverse_str(int head, int tail, char *data)
{
    int i = head;
    int j = tail;
    char temp;

    while(i < j)
    {
        temp = data[i];
        data[i] = data[j];
        data[j] = temp;
        i++;
        j--;
    }
}

int main()
{
    char data[20] = "cdregrtqvbr";
    int str_len;

    printf("%s\n", data);
    str_len = strlen(data);

    reverse_str(0, 2, data);
    reverse_str(3, str_len - 1, data);
    reverse_str(0, str_len - 1, data);
    printf("%s\n", data);
    printf("Hello world!\n");
    return 0;
}

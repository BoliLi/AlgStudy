#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../LBLsContainer/LBLsContainer.h"

#define MAX_CHAR 256

int main()
{
    char sub_str[10] = "bcababab";
    char main_str[50] = "fdsiuyrcvreabcabcbccafjbcababcababab";
    char sub_str1[10] = "bacdaefa";
    char main_str1[50] = "ijkaaefavreabcabcbafjbbacdaefaabab";
    int main_str_cnt, sub_str_cnt, main_str_cnt1, sub_str_cnt1;
    int next[9] = {0};
    int suffix[10] = {0};
    int bad_last_pos[MAX_CHAR];
    int good_last_pos[10] = {0};
    int i, j;


    sub_str_cnt = strlen(sub_str);
    main_str_cnt = strlen(main_str);

    i = kmp_str_search(main_str, sub_str, main_str_cnt, sub_str_cnt);

    printf("%s\n", main_str);
    printf("%s\n", sub_str);
    for(j = 0; j < sub_str_cnt; j++)
    {
        main_str[i++] = '*';
    }
    printf("%s\n", main_str);
    printf("-------------------------\n");

    sub_str_cnt1 = strlen(sub_str1);
    main_str_cnt1 = strlen(main_str1);

    i = bm_str_search(main_str1, sub_str1, main_str_cnt1, sub_str_cnt1);
    /*printf("%s\n", main_str1);
    printf("%s\n", sub_str1);
    for(j = 0; j < sub_str_cnt1; j++)
    {
        main_str1[i++] = '*';
    }
    printf("%s\n", main_str1);*/

    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * file;
    FILE * fp;
    unsigned char buf[139 * 48];
    int len, i;
    unsigned short a[139 * 24];
#if 0
    file = fopen("data1.raw", "rb");
    memset(buf, 0, 139 * 48);
    len = fread(buf, 1, 139 * 48, file);
    if(len != 139 * 48)
        printf("<%s-%d>~~~~~~~\n", __FUNCTION__, __LINE__);
    fp = fopen("mag.raw", "wb");
    fwrite(buf, 1, len, fp);
    fclose(fp);

    memset(buf, 0, 139 * 48);
    len = fread(buf, 1, 139 * 32, file);
    if(len != 139 * 32)
        printf("<%s-%d>~~~~~~~\n", __FUNCTION__, __LINE__);
    fp = fopen("thick.raw", "wb");
    fwrite(buf, 1, len, fp);
    fclose(fp);

    memset(buf, 0, 139 * 48);
    len = fread(buf, 1, 72, file);
    if(len != 72)
        printf("<%s-%d>~~~~~~~\n", __FUNCTION__, __LINE__);
    fp = fopen("uv.raw", "wb");
    fwrite(buf, 1, len, fp);
    fclose(fp);

    fclose(file);
#endif
#if 1
    fp = fopen("mag.raw", "rb");
    memset(a, 0, 139 * 48);
    len = fread(a, 1, 139 * 48, fp);
    if(len != 139 * 48)
        printf("<%s-%d>~%d~~~~~~\n", __FUNCTION__, __LINE__, len);
    printf("<%s-%d>~%d~~~~~~\n", __FUNCTION__, __LINE__, a[2]);
    fclose(fp);
#endif
    return 0;
}

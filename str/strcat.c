/*************************************************************************
	> File Name: strcat.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月15日 星期日 20时15分05秒
 ************************************************************************/

/*
 *strcat把src所指向的字符添加到dest结尾处（覆盖原dest结尾处的'\0'），并添加新的'\0'.
 *说明：src和dest所指内存区域不可以重叠，并且dest必须有足够的空间来容纳src的字符串，返回指向dest的指针。
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

char *kstrcat(char *dest, const char *src)
{
    assert((dest != NULL) && (src != NULL));

    char *p = dest;
    while(*p != '\0')
    {
        ++p;
    }
    while((*p++ = *src++) != '\0'){}
    p = NULL;

    return dest;
}

int main(int argc, char *argv[])
{
    char src[] = "China";
    char *dest = (char*)malloc(15 * sizeof(char));
    if(dest == NULL)
    {
        perror("malloc");
        return 1;
    }
    
    memcpy(dest, "I love ", strlen("I love "));
    kstrcat(dest, src);
    printf("dest: %s\n", dest);

    return 0;
}

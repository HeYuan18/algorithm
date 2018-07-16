/*************************************************************************
	> File Name: strcpy.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月15日 星期日 20时14分32秒
 ************************************************************************/

/*
 *字符串拷贝函数
 *
 */

#include<stdio.h>
#include<assert.h>

char *estrcpy(char *dest, const char *src)
{
    assert((NULL != dest) && (NULL != src));

    char *p = dest;
    while((*p++ = *src++) != '\0');
    p = NULL;

    return dest;
}

int main(int argc, char *argv[])
{
    char dest[] = "I like America";
    char src[] = "I love China";

    printf("%s\n", estrcpy(dest, src));

    return 0;
}

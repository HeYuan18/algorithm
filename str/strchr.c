/*************************************************************************
	> File Name: strchr.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月15日 星期日 20时16分58秒
 ************************************************************************/
/*
 *在指定字符串中查找字符'c'，并返回字符'c'第一次出现的位置。
 *含有'c'字符，那么返回指向字符'c'第一次出现的位置，否则返回NULL。
 */

#include<stdio.h>
#include<assert.h>

char *estrchr(const char *s, int c)
{
    assert(NULL != s);

    while(s && *s != c)
    {
        ++s;
    }

    return (char *)s;
}

int main(int argc, char *argv[])
{
    char s[] = "I love china";

    printf("%s,%c,%s\n", s, 'l', estrchr(s, 'l'));
    
    return 0;
}


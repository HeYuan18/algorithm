/*************************************************************************
	> File Name: strlen.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月15日 星期日 20时16分05秒
 ************************************************************************/

#include<stdio.h>
#include<assert.h>

int estrlen(const char *s)
{
    assert(NULL != s);

    int i = 0;
    while('\0' != *s)
    {
        ++s;
        ++i;
    }

    return i;
}

int main()
{
    char s[] ="i love china";
    
    printf("%s,%d\n", s, estrlen(s));
    
    return 0;
}

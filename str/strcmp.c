/*************************************************************************
	> File Name: strcmp.c
	> Author: 
	> Mail: 
	> Created Time: 2018年07月15日 星期日 20时14分57秒
 ************************************************************************/

/*
 *字符串比较函数，逐字符比较字符串
 *原字符串大于目的字符串--->返回差值为整数
 *原字符串小于目的字符串--->返回差值为负数
 *原字符串等于目的字符串--->返回值为0
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

int strcmp(const char *src, const char *dest)
{
    assert((src != NULL) && (dest != NULL));

    while((*src == *dest) && *dest)
    {
        ++src;
        ++dest;
    }

    return *(unsigned char*)src - *(unsigned char*)dest;
}

int main(int argc, char *argv[])
{
    char a[] = "i";
    char b[] = "i love";
    
    if(strcmp(a, b) >= 0)
    {
        printf("%s\n", a);
    }
    else
    {
        printf("%s\n", b);
    }

    return 0;
}

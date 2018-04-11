/*************************************************************************
	> File Name: atoi.c
	> Author: 
	> Mail: 
	> Created Time: 2018年04月11日 星期三 22时35分37秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int atoi(const char* str)
{
    int data = 0;
    bool tag = true;

    while(' ' == *str)
    {
        ++str;
    }

    if('-' == *str || '+' == *str)
    {
        if('-' == *str)
        {
            tag = false;
        }
        ++str;
    }

    while('0' <= *str && '9' >= *str)
    {
        data = data * 10 + (*str - '0');
        ++str;

        if(0 > data)
        {
            data = 2147483648;
            break;
        }
    }

    return data * (tag ? 1 : -1);
}

int main()
{
    char s[] = "65536";
    int  d = atoi(s);
    printf("d = %d\n", d);

    strcpy(s, "-1234");
    d = atoi(s);
    printf("d = %d\n", d);

    return 0;
}

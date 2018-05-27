/*************************************************************************
	> File Name: binaryS.c
	> Author: HeYuan
	> Mail: HeYuan951@Gmail.com
	> Created Time: 2018年04月15日 星期日 16时43分24秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int* Arr;

Arr init_arr(Arr l, int n)
{
    l = (Arr)malloc(sizeof(int) * n);
    if(NULL == l)
    {
        return NULL;
    }
    int i = 0;
    for(; i < n; ++i)
    {
        l[i] = 0;
    }

    return l;
}

Arr input_arr(Arr l, int n)
{
    printf("input: ");
    int i = 0;
    for(; i < n; ++i)
    {
        scanf("%d", &l[i]);
    }

    return l;
}

bool binaryS(Arr l, int n, int E)
{
    bool isGet = false;
    int head = 0, p = 0, tail = n;
    while(head <= tail)
    {
        p = (head + tail) / 2;
        if(E == l[p])
        {
            isGet = true;
            break;
        }
        if(E > l[p])
        {
            head = p + 1;
            continue;
        }
        if(E < l[p])
        {
            tail = p - 1;
            continue;
        }
    }

    if(isGet)
    {
        printf("Get:%d\n", E);
    }
    else
    {
        printf("Unexist\n");
    }

    return isGet;
}

void print_arr(Arr l, int n)
{
    printf("print_arr: ");
    int i = 0;
    for(; i < n; ++i)
    {
        printf("%d ", l[i]);
    }
    printf("\n");
}

Arr destory_arr(Arr l)
{
    if(NULL != l)
    {
        free(l);
        l = NULL;
    }

    return l;
}

int main()
{
    Arr L = NULL;
    int n = 0, E = 0;
    printf("len: ");
    scanf("%d", &n);
    if(0 == n)
    {
        printf("invaildInput\n");
        return 0;
    }

    L = init_arr(L, n);
    L = input_arr(L, n);
    
    printf("Search: ");
    scanf("%d", &E);

    binaryS(L, n, E);
    print_arr(L, n);

    return 0;
}

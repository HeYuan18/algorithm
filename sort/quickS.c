/*************************************************************************
	> File Name: quickS.c
	> Author: karma1996
	> Mail: karma1996@foxmail.com
	> Created Time: 2018年05月26日 星期六 21时42分40秒
 ************************************************************************/

#include<stdio.h>

void swap(int* const x, int* const y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int divided(int* const arr, int l, int r)
{
    int mid = (l + r) / 2;
    int hub = r - 1;
    if(arr[l] > arr[mid])
    {
        swap(&arr[l], &arr[mid]);
    }
    if(arr[l] > arr[r])
    {
        swap(&arr[l], &arr[r]);
    }
    if(arr[mid] > arr[r])
    {
        swap(&arr[mid], &arr[r]);
    }
    swap(&arr[mid], &arr[hub]);

    int i = l, j = hub;
    while(1)
    {
        while(arr[++i] < arr[hub]){}
        while(arr[--j] > arr[hub]){}

        if(i < j)
        {
            swap(&arr[i], &arr[j]);
        }
        else
        {
            break;
        }
    }
    swap(&arr[i], &arr[hub]);

    return i;
}

void conquer(int* const arr, int l, int r)
{
    if(l < r)
    {
        int p = divided(arr, l, r);
        conquer(arr, l, p - 1);
        conquer(arr, p + 1, r);
    }
}

void print_arr(int arr[], int len)
{
    int i = 0;
    for(; i < len; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {4,5,7,8,1,2,3,6};

    conquer(arr, 0, 7);

    print_arr(arr, 8);

    return 0;
}

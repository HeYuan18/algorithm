/*************************************************************************
	> File Name: mergeS.c
	> Author: karma1996
	> Mail: karma1996@foxmail.com
	> Created Time: 2018年05月26日 星期六 16时45分32秒
 ************************************************************************/

#include<stdio.h>

int tmp[8] = {0};

void merge(int* const arr, int l, int mid, int r)
{
    int i = l, j = mid + 1, k = 0;
    while(mid >= i && r >= j)
    {
        if(arr[i] > arr[j])
        {
            tmp[k++] = arr[j++];
        }
        else
        {
            tmp[k++] = arr[i++];
        }
    }

    if(mid < i)
    {
        for(; j <= r; ++j)
        {
            tmp[k++] = arr[j];
        }
    }
    if(r < j)
    {
        for(; i <= mid; ++i)
        {
            tmp[k++] = arr[i];
        }
    }
    
    k = 0;
    while(l <= r)
    {
        arr[l++] = tmp[k++];
    }
}

void divide(int* const arr, int l, int r)
{
    if(l < r)
    {
        int mid = (l + r) / 2;
        divide(arr, l, mid);
        divide(arr, mid + 1, r);
        merge(arr, l, mid, r);
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
    int arr[] = {4,3,7,5,6,2,1,8};

    divide(arr, 0, 7);

    print_arr(arr, 8);

    return 0;
}

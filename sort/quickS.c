/*************************************************************************
	> File Name: quickS.c
	> Author: karma1996
	> Mail: karma1996@foxmail.com
	> Created Time: 2018年05月27日 星期日 09时41分37秒
 ************************************************************************/

#include<stdio.h>

void swap(int* x, int* y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

int partition_medianValue(int* const arr, int l, int r)
{
    int mid = (l + r) / 2;
    int i = l, j = r;
    if(arr[l] > arr[mid])
    {
        swap(&arr[l], &arr[mid]);
    }
    if(arr[mid] > arr[r])
    {
        swap(&arr[mid], &arr[r]);
    }
    if(arr[l] > arr[r])
    {
        swap(&arr[l], &arr[r]);
    }
    swap(&arr[mid], &arr[--j]);

    while(1)
    {
        while(arr[++i] < arr[mid]){}
        while(arr[--j] > arr[mid]){}
        if(i < j)
        {
            swap(&arr[i], &arr[j]);
        }
        else
        {
            break;
        }
    }
    swap(&arr[i], &arr[r - 1]);

    return i;
}

int partition(int* const arr, int l, int r)
{
    int i = l, j = r;
    int pivot = arr[l];
    while(1)
    {
        while(arr[++i] < pivot){}
        while(arr[j] > pivot){--j;}
        if(i < j)
        {
            swap(&arr[i], &arr[j]);
        }
        else
        {
            break;
        }
    }
    swap(&arr[j], &arr[l]);

    return j;
}

void quick_sort(int* const arr, int l, int r)
{
    if(l < r)
    {
        int p = partition_medianValue(arr, l, r);
        quick_sort(arr, l, p - 1);
        quick_sort(arr, p + 1, r);
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
    int arr[] = {4,1,3,5,7,2,6};

    quick_sort(arr, 0, 6);

    print_arr(arr, 7);

    return 0;
}

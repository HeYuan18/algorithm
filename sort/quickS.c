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
    if(l == mid)
    {
        if(arr[l] > arr[r])
        {
            swap(&arr[l], &arr[r]);
        }

        return mid;
    }

    int i = l, j = r;
    if(arr[l] > arr[r])
    {
        swap(&arr[l], &arr[r]);
    }
    if(arr[mid] > arr[r])
    {
        swap(&arr[mid], &arr[r]);
    }
    if(arr[l] > arr[mid])
    {
        swap(&arr[l], &arr[mid]);
    }
    swap(&arr[mid], &arr[--j]);
    mid  = j;

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
    swap(&arr[i], &arr[mid]);

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
        //int p = partition(arr, l, r);
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
    int x[] = {4,1,3,5,2,2,6};
    int y[] = {1,2,3,4,5,6,7};
    int z[] = {0,2,4,4,4,5,1};

    quick_sort(x, 0, 6);
    print_arr(x, 7);

    quick_sort(y, 0, 6);
    print_arr(y, 7);

    quick_sort(z, 0, 6);
    print_arr(z, 7);

    return 0;
}

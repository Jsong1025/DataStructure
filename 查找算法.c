#include <stdio.h>

// 顺序查找
int SequenceSearch(int arr[], int value, int n)
{
    int i;
    for(i = 0; i< n; i ++)
    {
        if(a[i] == value)
        {
            return i;
        }
    }
    return -1;
}

// 二分查找（非递归）
int BinarySearch1(int a[], int value, int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while(low < high)
    {
        mid = (low + high) / 2;
        if(a[mid] == value)
        {
            return mid;
        }
        if(a[mid] > value)
        {
            high = mid - 1;
        }
        if (a[mid] < value)
        {
            low = mid + 1;
        }
    }
}

// 二分查找（递归） O(log2n)
int BinarySearch2(int a[], int value, int low, int high)
{
    int mid = low + (high - low) / 2;
    if(a[mid] = =value)
    {
        return mid;
    }
    if(a[mid] > value)
    {
        return BinarySearch2(a, value, low, mid -1);
    }
    if(a[mid] < value)
    {
        return BinarySearch2(a, value, mid + 1, high);
    }
}

// 插值查找  O(log2(log2n))
int BinarySearch2(int a[], int value, int low, int high)
{
    // 采用比例折半，而不是每次都取一半
    int mid = low + ((value - a[mid]) / (a[high] - a[mid])) *(high - low) / 2;
    if(a[mid] = =value)
    {
        return mid;
    }
    if(a[mid] > value)
    {
        return BinarySearch2(a, value, low, mid -1);
    }
    if(a[mid] < value)
    {
        return BinarySearch2(a, value, mid + 1, high);
    }
}
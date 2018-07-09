#include <stdio.h>

void Swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

// 冒泡排序

// 分类 ------------- 内部比较排序
// 数据结构 --------- 数组
// 最差时间复杂度 ---- O(n^2)
// 最优时间复杂度 ---- 如果能在内部循环第一次运行时,使用一个旗标来表示有无需要交换的可能,可以把最优时间复杂度降低到O(n)
// 平均时间复杂度 ---- O(n^2)
// 所需辅助空间 ------ O(1)
// 稳定性 ----------- 稳定
void BubbleSort(int A[], int n)
{
    for(int j = 0; j< n; j++)
    {
        for(int i = 0; i< n-1-j; i++)
        {
            if(A[i] > A[i+1])
            {
                Swap(A, i, i+1)
            }
        }
    }
}

// 分类 ------------ 内部比较排序
// 数据结构 --------- 数组
// 最差时间复杂度 ---- O(n^2)
// 最优时间复杂度 ---- 如果序列在一开始已经大部分排序过的话,会接近O(n)
// 平均时间复杂度 ---- O(n^2)
// 所需辅助空间 ------ O(1)
// 稳定性 ----------- 稳定

// 鸡尾酒排序
void CocktailSort(int A[], int n)
{
    int left = 0;
    int right = n -1;
    while(left < right)
    {
        for(int i = left; i < right; i++)
        {
            if(A[i] > A[i+1])
            {
                Swap(A, i, i+1);
            }
        }
        right--;
        for(int i = right; i > left; i--)
        {
            if(A[i-1] > A[i])
            {
                Swap(A, i-1, i);
            }
        }
        left++;
    }
}

// 分类 ------------- 内部比较排序
// 数据结构 --------- 数组
// 最差时间复杂度 ---- O(n^2)
// 最优时间复杂度 ---- O(n^2)
// 平均时间复杂度 ---- O(n^2)
// 所需辅助空间 ------ O(1)
// 稳定性 ----------- 不稳定

// 选择排序
void SelectSort(int A[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        int min = i;
        for(int j =i+1; j<n; j++)
        {
            if(A[j] < A[min])
            {
                min = j;
            }
        }
        if(min != i)
        {
            Swap(A, min, i);
        }
    }
}

// 分类 ------------- 内部比较排序
// 数据结构 --------- 数组
// 最差时间复杂度 ---- 最坏情况为输入序列是降序排列的,此时时间复杂度O(n^2)
// 最优时间复杂度 ---- 最好情况为输入序列是升序排列的,此时时间复杂度O(n)
// 平均时间复杂度 ---- O(n^2)
// 所需辅助空间 ------ O(1)
// 稳定性 ----------- 稳定

// 插入排序
void InsertionSort(int A[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int get = A[i];
        int j = i -1;
        while(j >=0 && A[j] > get)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = get;
    }
}

// 分类 ------------- 内部比较排序
// 数据结构 --------- 数组
// 最差时间复杂度 ---- O(n^2)
// 最优时间复杂度 ---- O(nlogn)
// 平均时间复杂度 ---- O(n^2)
// 所需辅助空间 ------ O(1)
// 稳定性 ----------- 稳定

// 二分插入排序
void InsertionSortDichotomy(int A[], int n)
{
    for(int i = i; i < n; i++)
    {
        int get = A[i];
        int left = 0;
        int right = i - 1;
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(A[min] > get)
            {
                right = mid -1;
            }
            else
            {
                left = mid + 1;
            }

        }
        for(int j = i-1; j >= left; j--)
        {
            A[j+1] = A[j];
        }
        A[left] = get;
    }
}

// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- 根据步长序列的不同而不同。已知最好的为O(n(logn)^2)
// 最优时间复杂度 ---- O(n)
// 平均时间复杂度 ---- 根据步长序列的不同而不同。
// 所需辅助空间 ------ O(1)
// 稳定性 ------------ 不稳定

// 希尔排序
void ShellSort(int A[], int n)
{
    int h = 0;
    while(h <= n)
    {
        h = 3 * h + 1;
    }

    while(h >= 1)
    {
        for(int i = h; i < n; i++)
        {
            int j = i - h;
            int get = A[i];
            while(j >= 0 && A[j] > get)
            {
                A[j + h] = A[j];
                j = j - h;
            }
            A[j + h] = get;
        }
        h = (h -1) /3;
    }
}

// 分类 -------------- 内部比较排序
// 数据结构 ---------- 数组
// 最差时间复杂度 ---- O(nlogn)
// 最优时间复杂度 ---- O(nlogn)
// 平均时间复杂度 ---- O(nlogn)
// 所需辅助空间 ------ O(n)
// 稳定性 ------------ 稳定

// 归并排序

// 把两个排好序的数组A[left..mid]和A[mid+1...right]合并
void merge(int A[], int left, int mid, int right)
{
    int len = right - left + 1;
    int *temp = new int[len];
    int index = 0;
    int i = left;
    int j = mid + 1;
    while(i <= mid && j<= right)
    {
        temp[index++] = A[i] <= A[j] ? A[i++] : A[j++];
    }
    while(i <= mid)
    {
        temp[index++] = A[i++];
    }
    while(i<=right)
    {
        temp[index++] = A[j++];
    }
    for(int k = 0; k < len; k++)
    {
        A[left++] = temp[k];
    }
}

// 递归归并排序
void MergeSortRecursion(int A[], int left, int right)
{
    if(left == right)
    {
        return;
    }
    int mid = (left + right) / 2;
    MergeSortRecursion(A, left, mid);
    MergeSortRecursion(A, mid + 1, right);
    merge(A, left, mid, right);
}

// 非递归归并排序
void MergeSortIteration(int A[], int len)
{
    int left, mid, right;
    for(int i = 1; i < len; i *= 2)
    {
        left = 0;
        while(left + i < len)
        {
            mid = left + i - 1;
            right = mid + i < len ? mid + i : len -1;
            Merge(A, left, mid, right);
            left = right + 1;
        }
    }
}
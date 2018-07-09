#include <stdio.h>
#include <memory.h>

/**
斐波那契查找与折半查找很相似，他是根据斐波那契序列的特点对有序表进行分割的。
他要求开始表中记录的个数为某个斐波那契数小1，及n=F(k)-1;
开始将k值与第F(k-1)位置的记录进行比较(及mid=low+F(k-1)-1),比较结果也分为三种

　　1）相等，mid位置的元素即为所求

　　2）>，low=mid+1,k-=2;

　　说明：low=mid+1说明待查找的元素在[mid+1,high]范围内，k-=2
         说明范围[mid+1,high]内的元素个数为n-(F(k-1))= Fk-1-F(k-1)=Fk-F(k-1)-1=F(k-2)-1个。

　　3）<，high=mid-1,k-=1。
　　说明：low=mid+1说明待查找的元素在[low,mid-1]范围内，k-=1
         说明范围[low,mid-1]内的元素个数为F(k-1)-1个。

　　
    最坏情况下，时间复杂度为O(log2n)，且其期望复杂度也为O(log2n)。
**/

const int max_size = 20; // 斐波那契数组长度

// 构造斐波那契数组
void Fibonacci(int *F)
{
    F[0] = 0;
    F[1] = 1;
    for(int i = 2; i < max_size; ++i)
    {
        F[i] = F[i-1] + F[i-2];
    }
}

int FibonacciSearch(int a[], int n, int value)
{
    int low = 0;
    int high = n - 1;

    int F[max_size];
    Fibonacci(F);

    int k = 0;
    while(n > F[k] - 1) // 计算n位于斐波那契数组的位置
    {
        ++k;
    }

    int *temp;
    temp = new int[F[k] -1];
    memcpy(temp, a, n*sizeof(int));
    for(int i = n; i< F[k]-1; ++i)
    {
        temp[i] = a[n-1];
    }

    while(low <= high)
    {
        int mid = low + F[k-1] -1;
        if(value < temp[mid])
        {
            high = mid -1;
            k -= 1;
        }
        else if(key > temp[mid])
        {
            low = mid + 1;
            k -= 2;
        }
        else
        {
            if(mid < n)
            {
                return mid;
            }
            else    // 位于拓展数值上
            {
                return n -1;
            }
        }
    }
    return -1;
}
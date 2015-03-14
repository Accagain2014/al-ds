/*
    基数排序
        最差时间复杂度：O(nk) //k是 数字位数
        基于非比较的排序
        稳定的
    算法描述
        从低位到高位依次排序，有点像计数排序
*/
#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;

int max_dit(int v[],int n)
{
    int d=1;
    int radix=10;

    for(int i=1;i<=n;i++)
    {
        if(v[i]>=radix)
        {
            d++;
            radix*=10;
        }
    }
    return d;

}
void cardinalsort(int v[],int n)
{
    int *tmp = new int[n];
    int *cnt = new int [10];
    int d = max_dit(v,n),radix=1;

    for(int i=1;i<=d;i++)
    {
        for(int j=0;j<10;j++)
            cnt[j]=0;
        for(int j=1;j<=n;j++)
            cnt[(v[j]/radix)%10]++;
        for(int j=1;j<10;j++)
            cnt[j]+=cnt[j-1];

        for(int j=n;j>=1;j--)
        {
            tmp[cnt[(v[j]/radix)%10]]=v[j];
            cnt[(v[j]/radix)%10]--;
        }
        for(int j=1;j<=n;j++)
            v[j]=tmp[j];
        radix*=10;

    }
    delete[]tmp;
    delete[]cnt;
    return ;

}

int main()
{
    int n=25,v[100];
    srand(time(NULL));

    for(int i=1;i<=n;i++)
    {
        v[i]=rand()%1000;
        printf("%d ",v[i]);
    }
    putchar('\n');
    cardinalsort(v,n);
    for(int i=1;i<=n;i++)
        printf("%d ",v[i]);
    putchar('\n');
    return 0;
}

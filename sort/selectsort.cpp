/*
    选择排序
        时间复杂度：O(n^2)
        描述：每次选择当前序列的最小的，放到序列的最前位置
        不稳定
*/
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

void selectsort(int v[],int n)
{
    for(int i=1;i<n;i++)
    {
        int cur=i;
        for(int j=i+1;j<=n;j++)
        {
            if(v[j]<v[cur])
                cur=j;
        }
        if(i!=cur)
            swap(v[cur],v[i]);
    }
    return ;
}

int main()
{
    int n=25,v[100];
    srand(time(NULL));

    for(int i=1;i<=n;i++)
    {
        v[i]=rand()%100;
        printf("%d ",v[i]);
    }
    putchar('\n');
    selectsort(v,n);
    for(int i=1;i<=n;i++)
        printf("%d ",v[i]);
    putchar('\n');
    return 0;
}

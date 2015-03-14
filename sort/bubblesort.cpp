/*
    冒泡排序
        时间复杂度：O(n^2)
        描述：每次选择当前序列的最大的移到最后的位置
        稳定
*/

#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

void bubblesort(int v[],int n)//1~n
{
    for(int i=1;i<n;i++) //只用选择n-1次就能完全排序
    {
        for(int j=1;j<n-i;j++)
        {
            if(v[j]>v[j+1])
                swap(v[j],v[j+1]);
        }
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
    bubblesort(v,n);
    for(int i=1;i<=n;i++)
        printf("%d ",v[i]);
    putchar('\n');
    return 0;
}

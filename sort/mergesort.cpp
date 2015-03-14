/*
    归并排序
        最坏时间复杂度：O(nlgn)
        描述：分治思想，归并操作将两个有序的序列合并
        稳定
*/
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

void merge(int v[],int le,int mid,int ri)
{
    int re[100];
    int i=le,j=mid+1,cnt=le;
    while(i<=mid&&j<=ri)
    {
        if(v[i]<=v[j])
           re[cnt++]=v[i++];
        else
            re[cnt++]=v[j++];
    }
    while(i<=mid)
        re[cnt++]=v[i++];
    while(j<=ri)
        re[cnt++]=v[j++];
    memcpy(v+le,re+le,(ri-le+1)*sizeof(*v)); //注意后面为字节个数
    /*for(i=le;i<=ri;i++)
        v[i]=re[i];*/

}
void mergesort(int v[],int le,int ri)
{
    if(le>=ri)
        return ;
    int mid=(le+ri)/2;
    mergesort(v,le,mid);
    mergesort(v,mid+1,ri);
    merge(v,le,mid,ri);

}
int main()
{
    int n=10,v[100];
    srand(time(NULL));

    for(int i=1;i<=n;i++)
    {
        v[i]=rand()%100;
        printf("%d ",v[i]);
    }
    putchar('\n');
    mergesort(v,1,n);
    for(int i=1;i<=n;i++)
        printf("%d ",v[i]);
    putchar('\n');
    return 0;
}

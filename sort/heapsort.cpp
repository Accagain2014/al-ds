/*
堆排序，利用父亲总大于以他为根的子树的性质。
稳定排序，时间复杂度O(nlgn)

    左孩子：i*2+1 右孩子i*2+2 父亲(i-1)/2
    先构建最大堆[或最小堆]，然后把根移到最后位置
*/

#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;

void shift_to_max(int v[],int cur,int len)
{
    int le_son=cur*2+1; //没有右儿子，就可以直接选左儿子

    while(le_son<len)
    {
        if(le_son+1<len&&v[le_son]<v[le_son+1])
            le_son++; //挑出大的儿子
        if(v[le_son]<v[cur]) //已经找不出最大的了
            break;
        swap(v[le_son],v[cur]);
        cur=le_son;
        le_son=cur*2+1;
    }
    return ;
}

void heapsort(int v[],int n)
{
    for(int i=(n-2)/2;i>=0;i--) //从非叶子节点开始,构建最大堆
        shift_to_max(v,i,n);

    for(int i=0;i<n;i++)
    {
        swap(v[0],v[n-i-1]);
        shift_to_max(v,0,n-i-1);
    }
}

int main()
{
    int v[100],n=25;

    srand(time(NULL));

    for(int i=0;i<n;i++)
    {
        v[i]=rand()%100;
        printf("%d ",v[i]);
    }
    printf("\n");


    heapsort(v,n);

    for(int i=0;i<n;i++)
        printf("%d ",v[i]);
    putchar('\n');
    return 0;
}

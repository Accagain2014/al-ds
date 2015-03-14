/*
    计数排序
        最优时间复杂度：O(n+k) //元素大小是0~k之间
        最坏时间复杂度：O(n+k)
        平均时间复杂度：O(n+k)
        稳定
    算法描述
        统计小于等于当前数的个数，根据数据大小范围来存
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

void countsort(int v[],int n) //1~n
{
    int k = 1001;//取值范围为1=< x < k
    int tmp[k],re[1001];
    memset(tmp,0,sizeof(tmp));
    //re = (int*)malloc(sizeof(v));

    for(int i=1;i<=n;i++) //tmp[i]表示数i出现的次数
        tmp[v[i]]++;
    for(int i=1;i<k;i++) //注意是k
        tmp[i]+=tmp[i-1]; //tmp[i]表示小于等于i的数的个数

    for(int i=n;i>=1;i--) //从后往前保证稳定性
    {
        re[tmp[v[i]]]=v[i];
        tmp[v[i]]--; //去掉当前元素
    }
    //memcpy(v,re,sizeof(v));
    for(int i=1;i<=n;i++)
        v[i]=re[i];
    return ;
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
    countsort(v,n);
    for(int i=1;i<=n;i++)
        printf("%d ",v[i]);
    putchar('\n');
    return 0;
}

/*
快速排序，平均时间复杂度O(nlgn),最坏时间复杂度O(n^2)
算法描述：
    分治思想，每次选择一个枢轴，以枢轴为中心，小于枢轴的放到一边，
大于枢轴的放到另一边，这样最终在最终排序后的位置也就确定了，然后
用同样的方式分治处理小于枢轴的一边和大于枢轴的一边
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

void quick(int v[],int low,int up) //从小到大排
{
    if(up-low<=0)
        return ;
    int target=v[up];
    int le=low-1;

    for(int i=low;i<up;i++)
    {
        if(v[i]<v[up])
        {
            le++;
            swap(v[le],v[i]);
        }
    }
    swap(v[le+1],v[up]);
    quick(v,low,le);   //le+1为枢轴
    quick(v,le+2,up);
    return ;
}

int main()
{
    srand(time(NULL));
    int v[100];

    for(int i=1;i<=13;i++)
    {
        v[i]=rand()%100;
        printf("%d ",v[i]);
    }
    putchar('\n');
    quick(v,1,13);
    for(int i=1;i<=13;i++)
        printf("%d ",v[i]);
    putchar('\n');

    return 0;
}


/*
    shell����
        �㷨������ÿ�ΰ���ͬ�������飬ͬ����ǰ��������С��ǰ�潻����
�ټ�����ǰ��ֱ��ǰ����ڣ���С����������
        ƽ��ʱ�临�Ӷȣ�O(n^1.3)
        ���ȶ�
*/
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

void shellsort(int v[],int n) //1~n
{
    int gap=n-1;
    do
    {
        gap=gap/3+1;
        for(int i=1+gap;i<=n;i++)
        {
            int cur=i;
            while(cur-gap>=1&&v[cur]<v[cur-gap])
            {
                swap(v[cur],v[cur-gap]);
                cur-=gap;
            }
        }
    }while(gap>1);
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
    shellsort(v,n);
    for(int i=1;i<=n;i++)
        printf("%d ",v[i]);
    putchar('\n');
    return 0;
}

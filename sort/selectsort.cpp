/*
    ѡ������
        ʱ�临�Ӷȣ�O(n^2)
        ������ÿ��ѡ��ǰ���е���С�ģ��ŵ����е���ǰλ��
        ���ȶ�
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

/*
    ��������
        ʱ�临�Ӷȣ�O(n^2)
        �������Ե�ǰԪ�أ�������ǰ�ң�ֱ���ҵ�����λ�ã�����
*/
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

void insertsort(int v[],int n) //1~n
{
    for(int i=2;i<=n;i++)
    {
        int cur=i;
        for(int j=i-1;j>=1;j--)
        {
            if(v[cur]>=v[j])
                break;
            else
            {
                swap(v[cur],v[j]);
                cur=j;
            }
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
    insertsort(v,n);
    for(int i=1;i<=n;i++)
        printf("%d ",v[i]);
    putchar('\n');

    return 0;
}

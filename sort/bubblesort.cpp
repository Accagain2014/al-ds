/*
    ð������
        ʱ�临�Ӷȣ�O(n^2)
        ������ÿ��ѡ��ǰ���е������Ƶ�����λ��
        �ȶ�
*/

#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

void bubblesort(int v[],int n)//1~n
{
    for(int i=1;i<n;i++) //ֻ��ѡ��n-1�ξ�����ȫ����
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

/*
��������ƽ��ʱ�临�Ӷ�O(nlgn),�ʱ�临�Ӷ�O(n^2)
�㷨������
    ����˼�룬ÿ��ѡ��һ�����ᣬ������Ϊ���ģ�С������ķŵ�һ�ߣ�
��������ķŵ���һ�ߣ���������������������λ��Ҳ��ȷ���ˣ�Ȼ��
��ͬ���ķ�ʽ���δ���С�������һ�ߺʹ��������һ��
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>

using namespace std;

void quick(int v[],int low,int up) //��С������
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
    quick(v,low,le);   //le+1Ϊ����
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


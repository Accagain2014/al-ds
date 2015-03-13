/*
���������ø����ܴ�������Ϊ�������������ʡ�
�ȶ�����ʱ�临�Ӷ�O(nlgn)

    ���ӣ�i*2+1 �Һ���i*2+2 ����(i-1)/2
    �ȹ�������[����С��]��Ȼ��Ѹ��Ƶ����λ��
*/

#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;

void shift_to_max(int v[],int cur,int len)
{
    int le_son=cur*2+1; //û���Ҷ��ӣ��Ϳ���ֱ��ѡ�����

    while(le_son<len)
    {
        if(le_son+1<len&&v[le_son]<v[le_son+1])
            le_son++; //������Ķ���
        if(v[le_son]<v[cur]) //�Ѿ��Ҳ���������
            break;
        swap(v[le_son],v[cur]);
        cur=le_son;
        le_son=cur*2+1;
    }
    return ;
}

void heapsort(int v[],int n)
{
    for(int i=(n-2)/2;i>=0;i--) //�ӷ�Ҷ�ӽڵ㿪ʼ,��������
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

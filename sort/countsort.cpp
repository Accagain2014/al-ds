/*
    ��������
        ����ʱ�临�Ӷȣ�O(n+k) //Ԫ�ش�С��0~k֮��
        �ʱ�临�Ӷȣ�O(n+k)
        ƽ��ʱ�临�Ӷȣ�O(n+k)
        �ȶ�
    �㷨����
        ͳ��С�ڵ��ڵ�ǰ���ĸ������������ݴ�С��Χ����
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

void countsort(int v[],int n) //1~n
{
    int k = 1001;//ȡֵ��ΧΪ1=< x < k
    int tmp[k],re[1001];
    memset(tmp,0,sizeof(tmp));
    //re = (int*)malloc(sizeof(v));

    for(int i=1;i<=n;i++) //tmp[i]��ʾ��i���ֵĴ���
        tmp[v[i]]++;
    for(int i=1;i<k;i++) //ע����k
        tmp[i]+=tmp[i-1]; //tmp[i]��ʾС�ڵ���i�����ĸ���

    for(int i=n;i>=1;i--) //�Ӻ���ǰ��֤�ȶ���
    {
        re[tmp[v[i]]]=v[i];
        tmp[v[i]]--; //ȥ����ǰԪ��
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

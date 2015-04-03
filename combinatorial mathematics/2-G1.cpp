#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define Maxn 10

int dp[Maxn][Maxn];
int n = 8,m1=4,m2=4;

bool iscan(int i,int j)
{
    if(i<j)
        return false;
    if(i&1)
    {
        if(j>(i/2))
            return true;
        return false;
    }
    if(j>=(i/2))
        return true;
    return false;
}

int main()
{
    memset(dp,-1,sizeof(dp));

    dp[1][1]=4;

    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(!iscan(i,j))
                continue;
            if(iscan(i-1,j))
                dp[i][j] = dp[i-1][j] * (m2-(i-1-j));
            if(iscan(i-1,j-1))
            {
                if(dp[i][j]==-1)
                {
                     dp[i][j] = dp[i-1][j-1] * (m1-(j-1));
                     if(i==2&&j==2)
                        printf("::%d\n",dp[2][2]);
                }
                else
                    dp[i][j] += dp[i-1][j-1] * (m1-(j-1));
            }
        }
        for(int j=1;j<=i;j++)
        {
            printf("i:%d j:%d %d\n",i,j,dp[i][j]);
        }

    }
    printf("%d\n",dp[8][4]);
    return 0;
}

#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int dp[500400][30];
int pre[500400][30];
char a[500400];
char ans[500400];
int main()
{
    int n,k;
    while(~scanf("%d%d",&n,&k))
    {
        scanf("%s",a+1);
        memset(dp,0,sizeof(dp));
        memset(pre,0,sizeof(pre));
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<k;j++)
            {
                dp[i][j]=0x3f3f3f3f;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<k;j++)
            {
                for(int kk=0;kk<k;kk++)
                {
                    if(j==kk)continue;
                    if(j==a[i]-'A')
                    {
                        if(dp[i][j]>dp[i-1][kk])
                        {
                            dp[i][j]=dp[i-1][kk];
                            pre[i][j]=kk;
                        }
                    }
                    else
                    {
                        if(dp[i][j]>dp[i-1][kk]+1)
                        {
                            dp[i][j]=dp[i-1][kk]+1;
                            pre[i][j]=kk;
                        }
                    }
                }
            }
        }
        int minn=0x3f3f3f3f;
        int pos;
        for(int i=0;i<k;i++)
        {
            if(dp[n][i]<minn)
            {
                minn=dp[n][i];
                pos=i;
            }
        }
        printf("%d\n",minn);
        if(minn==0)
        {
            printf("%s\n",a+1);
            continue;
        }
        int tt=n;
        ans[tt]=pos+'A';
        while(1)
        {
            ans[tt-1]=pre[tt][pos]+'A';
            pos=pre[tt][pos];
            tt--;
            if(tt==1)break;
        }
        for(int i=1;i<=n;i++)
        {
            printf("%c",ans[i]);
        }
        printf("\n");
    }
}
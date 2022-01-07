#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAX_N 1005
#define MOD 1000000007

using namespace std;

int n,k;
int ans=0;
int a[MAX_N];
int f[MAX_N];
int dp[MAX_N][MAX_N][2];
string s;

void read()
{
    cin>>s>>k;
    n=s.size();
    for(int i=0;i<n;i++) a[i+1]=s[i]-'0';
}

int cal_bit(int x)
{
    int cnt=0;
    int lowbit=x&-x;
    while(lowbit)
    {
        cnt++;
        x^=lowbit;
        lowbit=x&-x;
    }
    return cnt;
}

void cal_f()
{
    f[1]=0;
    for(int i=2;i<=1000;i++)
    {
        f[i]=f[cal_bit(i)]+1;
    }
}

void cal_dp()
{
    memset(dp,0,sizeof(dp));
    dp[1][0][0]=dp[1][1][1]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(dp[i][j][0])
            {
                dp[i+1][j][0]+=dp[i][j][0];
                dp[i+1][j+1][0]+=dp[i][j][0];
                dp[i+1][j][0]%=MOD;
                dp[i+1][j+1][0]%=MOD;
            }
            if(dp[i][j][1])
            {
                if(a[i+1])
                {
                    dp[i+1][j][0]+=dp[i][j][1];
                    dp[i+1][j+1][1]+=dp[i][j][1];
                    dp[i+1][j][0]%=MOD;
                    dp[i+1][j+1][1]%=MOD;
                }
                else
                {
                    dp[i+1][j][1]+=dp[i][j][1];
                    dp[i+1][j][1]%=MOD;
                }
            }
        }
    }
}

void cal_ans()
{
    for(int i=1;i<=1000;i++)
    {
        if(f[i]==k-1)
        {
            ans+=dp[n][i][0]+dp[n][i][1];
            ans%=MOD;
        }
    }
}

void work()
{
    if(k==0)
    {
        cout<<1<<endl;
        return;
    }
    cal_f();
    cal_dp();
    cal_ans();
    if(k==1) cout<<ans-1<<endl;
    else cout<<ans<<endl;
}

int main()
{
    read();
    work();
}
#include<bits/stdc++.h>
using namespace std;
const int N = 5e3+7;
int t[N][N];
int dp[N];
int a[N];
int ans[N];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],dp[i]=a[i];
    for(int i=1;i<=n;i++)
    {
         for(int j= i+1; j<=n;j++)
         {
            cin>>t[i][j];
            t[j][i]=t[i][j];
         }
    }
    for(int i = n;i>=1;i--)
    {
         for(int j= n ; j>i ;j--)
         { 
            if(t[i][j]&&dp[i]<dp[j]+a[i])
            {
                ans[i]=j;
                dp[i]=dp[j]+a[i];
            }
         }
    }
    int it =0 ;
    int ma =0 ;
    for(int i=1;i<=n;i++)if(ma<dp[i])ma=dp[i],it=i;
    while(it)
    {
        cout<<it<<' ';
        it = ans[it];
    }
    cout<<'\n';
    cout<<ma<<'\n';

    
}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    solve();
}
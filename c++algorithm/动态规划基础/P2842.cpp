#include<bits/stdc++.h>
using namespace std;
const int N = 10007;
const int INF = 1e9+7;
int dp[N]={0};
int a[N]={0};
void solve()
{
     int n,w;
     cin>>n>>w;
     for(int i=1;i<=n;i++)cin>>a[i];
     for(int i =1;i<=w ;i++)dp[i]=INF;
     for(int i= 1; i<=n;i++)
     {
         for(int j=a[i]; j<=w;j++)
         {
             dp[j] = min(dp[j-a[i]]+1,dp[j] );
         }
     }
     cout<<dp[w]<<'\n';

}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    solve();
}
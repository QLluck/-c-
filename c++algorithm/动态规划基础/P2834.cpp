#include<bits/stdc++.h>
using namespace std;
const int N = 10007;
const int INF = 1e9+7;
const int P = 1e9+7;
int dp[N]={0};
int a[N]={0};
void solve()
{
    int n,w;
    cin>>n>>w;
    dp[0]=1;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i= 1; i<=n;i++)
    {
          for(int j= a[i] ;j <=w ;j++)
          {
             dp[j] = (dp[j-a[i]]+dp[j])%P ;
          }
    }
    cout<<dp[w]<<'\n';
     

}
int main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    solve();
}
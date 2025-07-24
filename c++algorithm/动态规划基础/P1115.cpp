#include<bits/stdc++.h>
using namespace std ;
#define int long long
const int INF =1e9+7;
const int N =2e5+7 ;
int dp[N]={0};
int a[N]={0};
void solve()
{
    int n;
    cin>>n;
    dp[0]=-INF;
    for(int i=1;i<=n;i++)cin>>a[i];
    int ma = -INF;
    for(int i=1;i<=n;i++)
    {
        dp[i]=max(a[i],dp[i-1]+a[i]);
        ma = max(dp[i],ma);
    }
    cout<<ma<<'\n';
    


}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    solve() ;
 }
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
const int N = 5e5 + 7;

pair<int, int> dp[N];
int a[N] = {0};
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
    {
         cin>>a[i];
         dp[i].fi = 0;
         dp[i].se = 0;
    }
    dp[1].fi = 1;
    dp[1].se = 1;
    if(n>=2 && a[2]<a[1])
    {
        dp[2].fi = 3;
        dp[2].se = 2;
    }
    else if(n>=2)
    {
        dp[2].fi = 1;
        dp[2].se = 1;
    }
    for (int i = 3; i <= n;i++)
    {
          if(a[i-2]>a[i] )
          {
              dp[i].fi = dp[i].fi + dp[i - 2].fi + dp[i-2].se  ;
              dp[i].se = dp[i].se + dp[i - 2].se ;
          }
          if(a[i-1]>a[i] )
          {
              dp[i].fi = dp[i].fi + dp[i - 1].fi + dp[i-1].se  ;
              dp[i].se = dp[i].se + dp[i - 1].se ;
          }
          dp[i].fi += 1;
          dp[i].se += 1;
    }
    cout << dp[n].fi << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
const int N = 5e5+7;
pii a[N];
pii pix[N];
void solve()
{

  int n;
  cin>>n;
  int ans =0;
  int ma= -1e9-7;
  for(int i=1;i<=n;i++)cin>>a[i].fi;
  for(int i=1;i<=n;i++)cin>>a[i].se;
  for(int i=1;i<=n;i++)
  {
    ans += max(a[i].fi,a[i].se);
    ma = max(min(a[i].fi,a[i].se),ma);
  }
  ans +=ma;
  cout<<ans<<'\n';
  

    
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}

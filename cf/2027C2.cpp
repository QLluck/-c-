#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
const int N = 5e5 + 7;
pii a[N];
map<int,int>mp;

void solve()
{
    int n;
    cin>>n;
    mp.clear();
    int ans= 0;
    mp[0]=1;
    for(int i=1;i<=n;i++)cin>>a[i].fi,a[i].fi-=(n-i+1),a[i].se=i;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        if(a[i].fi<0)continue;
        if(mp[a[i].fi])
        {
            mp[a[i].fi+a[i].se-1]=1;
            ans =max(ans,a[i].fi+a[i].se-1);
        }
    }
    ans+=n;
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}
// n
//  n n-1 n-2  1
//
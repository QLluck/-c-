#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define pii pair<int,int>
#define fi first 
#define se second 
const int N = 5e5+7;
map<int,int>mp;
pii a[N];
pair<pii,int> b[N];
int c[N];

void solve()
{
   int n,k;
   cin >> n >> k;
    map<int, int> mp;
    int mi = 1e18 + 7;
    for (int i = 1; i <= n;i++)
        cin >> a[i].fi >> a[i].se, a[i].fi = a[i].fi - a[i].se + 1, mp[a[i].fi]++, mi = min(mi, a[i].fi);
    int ans = k - mi + 1;
    
    int ko = 0;
    int q = mi;
    int qt = 0;

    mp[k];
    for(auto p : mp)
    {
        int y = p.fi - q;
        if(p.se<=y)
        {
            ko += y - p.se;

        }
        else if(p.se<=ko+y)
        {
            ko = ko + y - p.se;
        }
        else 
        {
            ko = 0;
            ans += p.se - ko - y;
        }
        q = p.fi; 
        // cout << p.fi << ' ' << p.se << ' ' << ' ' << ko << ' ' << ans << '\n';
    }
    cout << ans-1 << '\n';
}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);

    int t;
   
    cin>>t;
    while(t--)
    solve();
}
//
//
//
//
//
//
// 21 
//  
//         1
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
const int N = 5e5 + 7;
int a[N];
int b[N];
int du[N];
int dan[N];
vector<int> t[N];
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
    {    t[i].clear();
        du[i] = 0;
        dan[i] = 0;
    }
   
    for (int i = 1; i < n;i++)
    {
        int u, v;
        cin >> u >> v;
        du[u]++;
        du[v]++;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    int le = 0;
    for (int i = 1; i <= n;i++)
    {    if(du[i]==1)
            le++;
        for (int j = 0; j < t[i].size();j++)if(du[t[i][j]]==1)
                dan[i]++;
    }
        int ans = 1e9;
    for (int i = 1; i <= n;i++)
    {      
            if(du[i]==1)
                ans = min(ans, le - dan[i] - 1);
                else 
                ans = min(ans, le - dan[i]);
            // cout << i << ' ' << dfs(i) << '\n';
        
    }
    cout << ans << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    // cout << 1 << ' ' << 3 << '\n';
    //  for (int i = 1; i <= 10; i++)
    //  {
    //      cout << po(3, i) << ' ' <<w(i)<<' '<<w(i+1)-3*w(i) << '\n';
    //  }
}
//

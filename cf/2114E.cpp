#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first 
#define se second
const int N = 2e5 + 7;
pii a[N];
vector<int> g[N];
int w[N];

// const int N = 507;
queue<int> que;
void bfs()
{
    map<int, int> mp;
    que.push(1);
    mp[1] = 1;
    a[1].fi = a[1].se = w[1];
    while(que.size())
    {
        int u = que.front();
        que.pop();
        for (int i = 0; i<g[u].size();i++)
        {
            int v = g[u][i];
            if(mp[v])
                continue;
            mp[v] = 1;
            a[v].fi = max(w[v] - a[u].se,w[v]);
            a[v].se =min( w[v] - a[u].fi,w[v]);
            que.push(v);
        }
    }
}
void solve()
{
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++)
    {
        cin >> w[i];
        g[i].clear();
    }
    for (int i = 1; i <= n - 1;i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    bfs();
    for (int i = 1; i <= n;i++)
        cout << a[i].fi << ' ';
    cout << '\n';
}

signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();

    // printb(2);
}
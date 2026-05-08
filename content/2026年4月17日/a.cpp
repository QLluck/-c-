#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int ,int>
#define fi first 
#define se second
const int N = 1e5 + 7;
map<PII, int> mp;
vector<int> t[N];
int d[N];
int f[N];
void bfs()
{
    priority_queue<PII> que;
    que.push({-1, 1});
    f[1] = 1;
    while(que.size())
    {
        int u = que.top().se;
        que.pop();
        for (int i = 0; i < t[u].size();i++)
        {
            int v = t[u][i];
            int w = max(d[u], d[v]);
            if(f[v])
                continue;
            f[v] = 1;
            d[v] = w;
            que.push({-w, v});
        }
    }

}
void solve()
{
    int n, m;
    cin >> n >> m;
    mp.clear();
    for (int i = 1; i <= n;i++)
        t[i].clear(),d[i]=i,f[i]=0;
    for (int i = 1; i <= m;i++)
    {
        int u, v;
        cin >> u >> v;
        if(u==v)
            continue;
        else if(mp[{u,v}])
            continue;
        mp[{u, v}] = 1;
        t[u].push_back(v);
    }
    bfs();
    for (int i = 1; i <= n;i++)
    {
        if(f[i]==0)
            cout << -1 << ' ';
        else
            cout << d[i] << ' ';
    }
    cout << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    solve();
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>
#define fi first
#define se second
const int N = 2e5 + 7;
int a[N];
int pa[N];
vector<int> t[N];
stack<int> sta[N];
map<int, int> me;
PII ans[3 * N];
int it = 0;
int flag = 0;
int n;
int zd = 0;
void dfs(int d, int u)
{
    if (me[u] || flag)
        return;
    me[u] = 1;
    pa[d] = u;
    if (u == n)
    {
        flag = 1;
        zd = d;
        return;
    }
    for (int i = 0; i < t[u].size(); i++)
    {
        if (flag == 1)
            return;
        int v = t[u][i];
        dfs(d + 1, v);
    }
    me[u] = 0;
}
int bfs(int s)
{
    queue<PII> que;
    que.push({s, 1});
    me.clear();
    int ma = 0;
    me[s] = 1;
    while (que.size())
    {
        int u = que.front().fi;
        int d = que.front().se;

        // cout << u << ' ' << d << '\n';
        sta[d].push(u);
        ma = max(d, ma);
        que.pop();

        for (int i = 0; i < t[u].size(); i++)
        {
            int v = t[u][i];
            if (me[v])
                continue;
            me[v] = 1;
            que.push({v, d + 1});
        }
    }
    return ma;
}
void solve()

{
    flag = 0;
    cin >> n;
    it = 0;
    for (int i = 1; i <= n; i++)
        t[i].clear();
    for (int i = 1; i <= n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        t[u].push_back(v);
        t[v].push_back(u);
    }
    me.clear();
    dfs(1, 1);
    int ma = bfs(1);
    int d = ma;
    int sum = 0;
    ans[0].fi = 0;
    while (d)
    {
        int u = 0;

        if ((d & 1) ^ (sum & 1) == 0)
            u = sta[d].top(), sta[d].pop();
        else
        {
            ans[++it].fi = 1;
            sum++;
            continue;
        }

        if (d <= zd && u == pa[d])
        {
            if (sta[d].size() == 0)
            {
                d--;
                continue;
            }
            else
                u = sta[d].top(), sta[d].pop();
        }
        if (ans[it].fi == 2)
        {
            ans[++it].fi = 1;
            sum++;
            sta[d].push(u);
            continue;
        }
        ans[++it].fi = 2, ans[it].se = u;
        if (sta[d].size() == 0)
            d--;
    }

    int l = 1;
    while (l < zd)
    {
        if (ans[it].fi == 2)
        {
            ans[++it].fi = 1;
            sum++;
            continue;
        }

        if ((l & 1) ^ (sum & 1) == 0)
            ans[++it].fi = 2, ans[it].se = pa[l], l++;
        else
            ans[++it].fi = 1, sum++;
    }

    cout << it << '\n';
    for (int i = 1; i <= it; i++)
    {
        if (ans[i].fi == 1)
            cout << 1 << '\n';
        else
            cout << ans[i].fi << ' ' << ans[i].se << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}
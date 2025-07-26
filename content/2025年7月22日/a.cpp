#include <bits/stdc++.h>
using namespace std;
#define int long long

const int INF = 1e18 + 7;
const int N = 2e5 + 7;
const int P = 998244353;
vector<pair<int, int>> t[N];
map<pair<int, int>, int> mp;
int fan = 1;
int po(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % P;
        b >>= 1;
        a = a * a % P;
    }
    return res % P;
}
int ans = 0;
int n, m;
struct node
{
    int l, r, p, fan;
};
queue<node> que;
void bfs(int l, int r, int p)
{

    que.push({l, r, p, (1 - p + P) % P});
    while (que.size())
    {
        p = que.front().p;
        l = que.front().l;
        r = que.front().r;

        int fa = que.front().fan;

        que.pop();
        if (r == n)
        {
            p = p * fan % P * po(fa, P - 2) % P;
            ans = (ans + p) % P;

            continue;
        }
        for (int i = 0; i < t[r + 1].size(); i++)
        {
            int l1 = r + 1;
            int r1 = t[l1][i].first;
            int p1 = t[l1][i].second;
            int fan1 = fa * (1 - p1 + P) % P;

            que.push({l1, r1, p1, fan1});
        }
    }
}
void solve()
{

    cin >> m >> n;
    ans = 0;
    for (int i = 1; i <= n; i++)
        t[i].clear();
    for (int i = 1; i <= m; i++)
    {
        int l, r, p, q;
        cin >> l >> r >> p >> q;
        p = p * po(q, P - 2) % P;

        t[l].push_back({r, p});

        fan = fan * (1 - p + P) % P;
    }
    int it = 1;

    for (int i = 0; i < t[1].size(); i++)
    {
        bfs(1, t[1][i].first, t[1][i].second);
    }

    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    // int t;
    // cin >> t;
    // while(t--)
    solve();
}
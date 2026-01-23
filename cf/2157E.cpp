#include <bits/stdc++.h>

using namespace std;
#define int long long
#define PII pair<int, int>
#define fi first
#define se second
const int N = 2e5 + 7;

int a[N];

int debugid = 0;
int ans = 0;
int it;
int n, k;
map<int, int> mp;
void bfs()
{
    queue<PII> que;
    for (int i = it;  i>=1; i--)
    {
        que.push({a[i], 0});
    }
    while (que.size())
    {
        int u = que.front().fi;
        int uid = que.front().se;
        ans = max(ans, uid);
        // cout << u << ' ' << uid << '\n';
        que.pop();
        if (mp[u] > k)
        {
            mp[u + 1] += mp[u] - 1;
            mp[u] = 1;
            // cout << u << ' ' << u + 1 << ' ' << uid << '\n';
            que.push({u + 1, uid + 1});
        }
    }
}
void solve()
{

    mp.clear();
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i], mp[a[i]]++;
    sort(a + 1, a + n + 1);
    it = unique(a + 1, a + n + 1) - a - 1;
    int id = 0;
    ans = 0;

    bfs();
    cout << ans << '\n';
}
// 0 1 2 3 4 5 6 7
// 0 1 2 3 0 1 2 3

signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}
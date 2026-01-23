#include <bits/stdc++.h>

using namespace std;
#define int long long
#define PII pair<int, int>
#define fi first
#define se second
const int N = 2e5 + 7;
int a[N];
PII ans[N];
int it = 0;
void solve()
{
    int n;
    it = 0;
    cin >> n;
    stack<int> sta;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (sta.size())
        {
            if (a[i] < sta.top())
            {
                sta.push(a[i]);
                continue;
            }
            int u = sta.top();
            while (sta.size() && sta.top() < a[i])
            {
                ans[++it].fi = sta.top(), ans[it].se = a[i];
                u = min(sta.top(), u);
                sta.pop();
            }
            sta.push(u);
        }
        else
            sta.push(a[i]);
    }
    if (sta.size() != 1)
        cout << "NO" << '\n';
    else
    {
        cout << "YES" << '\n';
        for (int i = 1; i <= it; i++)
            cout << ans[i].fi << ' ' << ans[i].se << '\n';
    }
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    t = 1;
    cin >> t;
    while (t--)
        solve();
}
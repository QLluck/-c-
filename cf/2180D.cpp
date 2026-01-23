#include <bits/stdc++.h>

using namespace std;
#define int long long
#define PII pair<int, int>
#define fi first
#define se second
const int N = 2e5 + 7;
PII gc[N];
int a[N];
int l[N];
int r[N];
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 2; i <= n - 1; i++)
    {
        l[i] = min(a[i] - a[i - 1], a[i + 1] - a[i]);
        r[i] = max(a[i + 1] - a[i], a[i] - a[i - 1]);
    }
    if (n == 1)
    {
        cout << 0 << '\n';
        return;
    }
    int ans = 0;
    int ma = 1;
    for (int i = 1; i + 1 <= n; i++)
    {
        if (i == 1)
            ans++;
        else if (i == n - 1)
            ans++;
        else
        {
            int le = a[i + 1] - a[i];
            if (le <= l[i] || le <= l[i + 1])
                ans++;
        }
    }
    cout << ans << '\n';
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
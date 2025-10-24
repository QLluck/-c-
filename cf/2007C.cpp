#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
const int N = 2e5 + 7;
int a[N];
pii b[N];
void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    int k = __gcd(x, y);
    for (int i = 1; i <= n; i++)
        cin >> a[i], a[i] %= k;
    sort(a + 1, a + n + 1);
    b[n + 1].fi = 0;
    b[n + 1].se = 1e18 + 7;
    for (int i = n; i >= 1; i--)
    {
        b[i].fi = max(b[i + 1].fi, a[i]);
        b[i].se = min(b[i + 1].se, a[i]);
    }
    int mi = 1e18 + 7;
    int ma = 0;
    int ans = b[1].fi - b[1].se;
    for (int i = 1; i < n; i++)
    {
        mi = min(mi, a[i] + k);
        ma = max(ma, a[i] + k);
        // cout << i << ' ' << b[i + 1].fi << ' ' << b[i + 1].se << '\n';
        ans = min(ans, (max(ma, b[i + 1].fi)) - (min(mi, b[i + 1].se)));
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
}

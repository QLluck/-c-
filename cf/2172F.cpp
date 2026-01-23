#include <bits/stdc++.h>

using namespace std;
#define int long long
#define PII pair<int, int>
#define fi first
#define se second
const int N = 2e5 + 7;
PII gc[N];
int a[N];
int gcd(int a, int b)
{
    if (a > b)
        swap(a, b);
    while (a)
    {
        int tmp = b % a;
        b = a;
        a = tmp;
    }
    return b;
}
void solve()
{

    int n;
    cin >> n;
    gc[0].fi = 0;
    gc[n + 1].se = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i], gc[i].fi = gcd(a[i], gc[i - 1].fi);
    for (int i = n; i >= 1; i--)
    {
        gc[i].se = gcd(gc[i + 1].se, a[i]);
    }
    int ans = 0, l = 1, r = n;
    while (l <= r)
    {
        if (l == r)
            ans += min(gc[l].se, gc[r].fi);
        else if (l == 1 && r == n)
            ans += gc[r].fi;
        else
            ans += min(gc[l].se, gc[l].fi), ans += min(gc[r].fi, gc[r].se);
        l++, r--;
        // cout<<gc[l].se<<' '<<gc[r].fi<<'\n';
    }
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    // cin >> t;
    t = 1;
    while (t--)
        solve();
}
#include <bits/stdc++.h>

using namespace std;
#define int long long
#define PII pair<int, int>
#define fi first
#define se second
const int N = 2e5 + 7;
int a[N] = {0};
int ans[N] = {0}, it;
pair<int, PII> b[N];
priority_queue<PII> que;
int n, k, x;
bool check(int mid)
{
    it = 0;
    if (mid == 0)
    {
        for (int i = 0; i < k - 1; i++)
            ans[++it] = i;
        return 1;
    }
    for (int i = 0; (i <= a[1] - mid) && (it < k); i++)
        ans[++it] = i;
    for (int i = x; (i >= a[n] + mid) && (it < k); i--)
        ans[++it] = i;
    for (int i = 1; (i <= n - 1) && (it < k); i++)
    {
        int s = a[i] + mid;
        int z = a[i + 1] - mid;
        for (int j = s; (j <= z) && (it <k); j++)
            ans[++it] = j;
    }
    return (it >= k);
}
void solve()
{

    cin >> n >> k >> x;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[n + 1] = -100;
    sort(a + 1, a + n + 1);
    n = unique(a + 1, a + n + 1) - a - 1;
    int r = x + 1;
    int l = -1;
    while (l + 1 < r)
    {
        int mid = (l + r) >> 1;
        // cout << mid << ' ' << l << ' ' << r << ' ' << it << '\n';
        if (check(mid))
            l = mid;
        else
            r = mid;
        // cout << mid << ' ' << l << ' ' << r << ' ' << it << '\n';
    }
    check(l);
    for (int i = 1; i <= it; i++)
        cout << ans[i] << ' ';
    cout << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}
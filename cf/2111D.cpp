#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
const int N = 2e5 + 7;
pii r[N];
pii c[N];
pii a[N];
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].se;
        a[i].fi = a[i].se / 100;
    }
    sort(a + 1, a + m + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (i & 1)
            {
                if (j & 1)
                    cout << a[i / 2 + 1].se << ' ';
                else
                    cout << a[m - i / 2].se << ' ';
            }
            else
            {
                if (j & 1)
                    cout << a[m - i / 2 + 1].se << ' ';
                else
                    cout << a[i / 2].se << ' ';
            }
        }
        cout << '\n';
    }
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
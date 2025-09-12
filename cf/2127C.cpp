#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
const int N = 5e5 + 7;
pii a[N];
pii b[N];
int so[5];
bool cmp(pii a, pii b)
{
    if (a.fi != b.fi)
        return a.fi < b.fi;
    else
        return a.se < b.se;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i].fi, b[i].se = a[i].fi;
    for (int i = 1; i <= n; i++)
        cin >> a[i].se, b[i].fi = a[i].se;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += abs(a[i].fi - a[i].se);

    sort(a + 1, a + 1 + n, cmp);
    sort(b + 1, b + 1 + n, cmp);
    int mi = 1e18 + 7;
    for (int i = 1; i < n; i++)
    {
        so[1] = a[i].fi;
        so[2] = a[i].se;
        so[3] = a[i + 1].fi;
        so[4] = a[i + 1].se;
        int yu = abs(a[i].fi - a[i].se) + abs(a[i + 1].fi - a[i + 1].se);
        sort(so + 1, so + 5);
        int bi = abs(so[4] - so[1]) + abs(so[3] - so[2]);
        mi = min(mi, bi - yu);
    }
    for (int i = 1; i < n; i++)
    {
        so[1] = b[i].fi;
        so[2] = b[i].se;
        so[3] = b[i + 1].fi;
        so[4] = b[i + 1].se;
        int yu = abs(b[i].fi - b[i].se) + abs(b[i + 1].fi - b[i + 1].se);
        sort(so + 1, so + 5);
        int bi = abs(so[4] - so[1]) + abs(so[3] - so[2]);

        mi = min(mi, bi - yu);
        if (bi - yu < 0)
        {
          //  cout << i << ' ' << bi << ' ' << yu << ' ' << b[i].fi << ' ' << b[i].se <<' '<< b[i + 1].fi << ' ' << b[i + 1].se << '\n';
        }
    }
    cout << ans + mi  << '\n';
}//5   6
// 100 4    4 5 6 100


signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
    // cout << 1 << ' ' << 3 << '\n';
    //  for (int i = 1; i <= 10; i++)
    //  {
    //      cout << po(3, i) << ' ' <<w(i)<<' '<<w(i+1)-3*w(i) << '\n';
    //  }
}
//

#include <bits/stdc++.h>

using namespace std;
#define int long long
#define PII pair<int, int>
#define fi first
#define se second
const int N = 2e5 + 7;
const int INF = 1e18 + 7;
const int IN = 1e9;
PII a[N];

void solve()
{

    int n;
    cin >> n;
    int mijia = INF;
    int mijian = INF;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        // a[i].fi = x, a[i].se = y;
        mijia = min(-x - y, mijia);
        mijian = min(x - y, mijian);
    }
    int tmp;
    cout << "? U " << IN << '\n';
    cin >> tmp;
    cout.flush();
    cout << "? U " << IN << '\n';
    cin >> tmp;
    cout.flush();
    cout << "? R " << IN << '\n';
    cin >> tmp;
    cout.flush();
    cout << "? R " << IN << '\n';
    cin >> tmp;
    cout.flush();
    // cout << tmp << '\n';
    int res1 = tmp - 4 * IN - mijia;
    cout << "? L " << IN << '\n';
    cin >> tmp;
    cout.flush();
    cout << "? L " << IN << '\n';
    cin >> tmp;
    cout.flush();
    cout << "? L " << IN << '\n';
    cin >> tmp;
    cout.flush();
    cout << "? L " << IN << '\n';
    cin >> tmp;
    cout.flush();
    int res2 = tmp - mijian-4*IN;
    // cout << res1 << ' ' << res2 << '\n';
    cout << "! " << ((res1 - res2) / 2) << ' ' << ((res1 + res2) / 2) << '\n';
    cout.flush();
}
// x + y +4INF + min(-xi-yi);
// x+y
//
// min(xi - (xi+2*in)+ y+2*n-yi )=y-x+4*in +min(xi-yi)
signed main()
{
    // ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    // t = 1;
    while (t--)
        solve();
}
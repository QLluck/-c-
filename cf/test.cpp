#include <bits/stdc++.h>

using namespace std;
#define int long long
#define PII pair<int, int>
#define fi first
#define se second
const int N = 2e5 + 7;
const int INF = 1e18 + 7;
const int IN = 100;
PII a[N];

void solve()
{

    do
    {

        if (check(i1, j1) && a[i1][j1] == '#')
            n1++;
        i1++, j1++;
        cout << i1 << ' ' << j1 << '\n';
        // debug(check(i1, j1));
    } while (check(i1, j1));
}
signed main()
{
    // ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    // t = 1;
    while (t--)
        solve();
}
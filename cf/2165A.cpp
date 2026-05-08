#include <bits/stdc++.h>

using namespace std;
#define int long long
#define PII pair<int, int>
#define fi first
#define se second
const int N = 2e5 + 7;
int a[N];
int b[N], itb;
void solve()
{
    itb = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        int xia = (i + 1) % n;
        if (xia == 0)
            xia = n;
        int ma = max(a[i], a[xia]);
        b[++itb] = ma;
    }
    sort(b + 1, b + itb + 1);
    int sum = 0;
    for (int i = 1; i <= n - 1; i++)
        sum += b[i];
    cout << sum << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}
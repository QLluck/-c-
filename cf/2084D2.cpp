#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 7;
int a[N] = {0};
int n, m, k;
void solve()
{

    cin >> n >> m >> k;
    //    for(int i=1; i<=n;i++)cin>>a[i];
    int l = 0, r = 1e9 + 7;
    int ma = n / (m + 1);
    l = max(ma, k);
    int it = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % l == 0)
            it = 0;
        a[i + 1] = it;
        // cout << it << ' ' << num << '\n';
        it++;
    }
    for (int i = 1; i <= n; i++)
        cout << a[i] << ' ';

    cout << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
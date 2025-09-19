#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 7;
int a[N] = {0};
int b[N] = {0};
int c[N] = {0};

int nc, n, m;
int check(int mid)
{
    int ita = 1;
    int itb = 1;
    int f = 1;
    int biao = (mid == 0) ? 0 : c[mid];
    while (ita <= n && itb <= m)
    {
        if (b[itb] == biao && f)
        {

            f = 0;
            itb++;
            continue;
        }
        if (a[ita] >= b[itb])
            ita++, itb++;
        else
        {
            ita++;
        }
    }
    // cout << "b" << ' ' << itb << ' ' << m + 1 << '\n';

    if (itb == m + 1)
        return 0;
    else
        return 1;
}
void solve()
{

    cin >> n;
    for (int i = 1; i <= n*2;i++)
        cin >> a[i];
    sort(a + 1, a + n*2 + 1);
    int ans = 0;
    for (int i = 1; i <= 2 * n; i += 2)
    {
        ans += a[i + 1] - a[i];
    }
    cout << ans << ' ';
    for (int i = 2*n; i >=1;i--)
        cout << a[i] << ' ';
    cout << '\n';
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
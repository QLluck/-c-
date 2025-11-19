#include <bits/stdc++.h>

using namespace std;
#define int long long
#define PII pair<int, int>
#define fi first
#define se second
const int N = 2e5 + 7;
int a[N];
int b[N];
int a1[N], ita;
int a1[N], ita;
void solve()
{
    int n, k;
    cin >> n;
    it = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > b[i])
        {
            cout << "NO" << '\n';
            return;
        }
    }
    int l = -1;
    for (int i = 1; i <= n; i++)
    {
        if (l != b[i])
        {
            l = b[i];
            z[++it] = l;
        }
    }
    l = -1;
    int itb = 0;
    for (int i = 1; i <= n; i++)
    {
        if (l != a[i])
        {
            l = a[i];
            b[++itb] = l;
        }
    }
    int ita = 0;
    int itb = 0;
}
// 0 1 2 3 4 5 6 7
// 0 1 2 3 0 1 2 3
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
const int N = 2e5 + 7;
const int mod = 1e9 + 7;
int a[N];
int jie[N];
int po(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
        {
            res *= a;
            res %= mod;
        }
        b >>= 1;
        a *= a;
        a %= mod;
    }
    return res;
}
void init()
{
    jie[0] = 1;
    for (int i = 1; i < N; i++)
    {
        jie[i] = jie[i - 1] * i;
        jie[i] %= mod;
    }
}
void solve()
{
    int n, k;

    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    init();
    cin >> t;
    while (t--)
        solve();
}

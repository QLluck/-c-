#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define endl '\n'
#define fi first
#define se second
const int N = 2e5 + 7;
const int mod = 1e9 + 7;
int a[N] = {0};
int jie[N] = {0};
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
int C(int x, int y)
{
    int res = jie[x];
    int chu = jie[y];
    chu *= jie[x - y];
    chu %= mod;
    res = res * po(chu, mod - 2) % mod;
    return res;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    int n1 = 0, n0 = 0;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        if (a)
            n1++;
        else
            n0++;
    }
    int k1 = k / 2 + 1;
    int it1 = min(n1, k);
    int it0 = (k - it1);
    int ans = 0;
    while (it1 >= k1 && it0 <= n0)
    {

        ans += (C(n1, it1) * C(n0, it0)) % mod;
        ans %= mod;
        it1--;
        it0++;
    }
    cout << ans << endl;
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

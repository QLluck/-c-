#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define PII pair<int, int>
using namespace std;
const int N = 2e5 + 10;
const int mod = 1e9 + 7;
int a[N];
int jie[N];
void init()
{
    jie[0] = 1;
    for (int i = 1; i < N; i++)
    {
        jie[i] = i * jie[i - 1];
        jie[i] %= mod;
    }
}
int po(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return res;
}
int C(int a, int b)
{
    if (a == 0)
        return 1;
    return jie[a] * po(jie[a - b] * jie[b] % mod, mod - 2) % mod;
}
int A(int a, int b)
{
    if (a == 0)
        return 1;
    return jie[a] * po(jie[a - b] % mod, mod - 2) % mod;
}
// int A(int x, int y)
// {
//     if (x == 0 || y == 0)
//     {
//         return 1;
//     }
//     int ret = 1;
//     for (int i = y; i >= y - x + 1; i--)
//     {
//         ret *= i;
//         ret %= mod;
//     }
//     return ret;
// }
void solve()
{
    int n, x, pos;
    cin >> n >> x >> pos;
    int l = 0, r = n;
    int ans1 = 0, ans2 = 0;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (mid <= pos)
        {
            if (mid != pos)
            {
                a[mid] = 1;
                ans1++;
            }
            l = mid + 1;
        }
        else
        {
            a[mid] = 2;
            ans2++;
            r = mid;
        }
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     if (a[i] == 1)
    //         ans1++;
    //     else if (a[i] == 2)
    //         ans2++;
    // }
  
    int ans = 1;
    int Min = x - 1, Max = n - x;
    if (ans1 > Min || ans2 > Max)
    {
        cout << 0 << endl;
        return;
    }
    ans *= C(Min, ans1) * A(ans1, ans1) % mod;
    ans %= mod;
    ans *= C(Max, ans2) * A(ans2, ans2) % mod;
    ans %= mod;
    int p = n - 1 - ans1 - ans2;
    ans *= A(p, p);
    ans %= mod;
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    //    cin>>T;
    init();
    while (T--)
    {
        solve();
    }
}
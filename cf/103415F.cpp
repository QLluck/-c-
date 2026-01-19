#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 3e5 + 7;
int a[N];
const int mod = 998244353;
void te()
{
    a[1] = 1;
    a[2] = 1;
    for (int i = 3; i < N; i++)
        a[i] = (a[i - 1] + a[i - 2]) % mod;
}
void solve()
{
    int n;
    cin >> n;
    cout << a[n] << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    t = 1;
    te();
    // cin>>t;
    while (t--)
        solve();
}

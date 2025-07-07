#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int N = 1e7 + 7;
const ll P = 998244353;
ll gcd(ll a, ll b)
{
    if (a > b)
        swap(a, b);
    while (a)
    {
        ll temp = b % a;
        b = a;
        a = temp;
    }
    return b % P;
}
ll lcm(ll a, ll b)
{
    return a / gcd(a, b) % P * b % P;
}
ll po(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % P;
        b >>= 1;
        a = a * a % P;
    }
    return res % P;
}
void solve()
{
    int n;
    cin >> n;
    ll ma = 0;
    ll lc = 1;
    ma = 1;
    for (int i = 2; i <= n; i++)
    {
        lc = lcm(lc, i);
        ma = max(ma, lc);
    }
    ll sum = 0;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        sum = (sum + ma * po(i, P - 2)) % P;

        ans = (ans + (sum - i * ma % P * po(i, P - 2) % P + P) % P) % P;
    }
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    solve();
    return 0;
}
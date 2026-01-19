#include <bits/stdc++.h>

using namespace std;
#define int long long
#define PII pair<int, int>
#define fi first
#define se second
const int N = 2e5 + 7;
const int INF = 1e18 + 7;
const int IN = 100;
int a[N];
int mp[N];
void solve()
{
    // map<int, int> mp;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i <= n+2;i++)
        mp[i] = 0;
        for (int i = 1; i <= n; i++)
            cin >> a[i], mp[a[i]]++;
    int it = 0;
    int sum = 0;
    int duo = 0;
    int dan = 0;
    int it2 = -1;
    int sum1 = 0;
    int sum2 = 0;
    while (mp[it] != 0)
    {

        if (mp[it] >= 2)
        {
            if (it2 == -1)
                it2 = it;

            sum += mp[it];
            duo++;
        }
        else if (mp[it] == 1)
        {
            sum1 += it;
            if (it2 == -1)
                sum2 += it;
            dan++;
        }
        it++;
    }
    // cout << it << ' ' << it2 << ' ' << duo << '\n';
    int ans = 0;
    if (duo == 0)
    {

        ans = sum1;
        if ((n - it) == 1)
            ans += (n - it) * it;
        else
        {
            if (k & 1)
                ans += (n - it) * it;
            else
                ans += (n - it) * (it + 1);
        }
    }
    else
    {
        if (k == 1)
        {
            ans = sum1;
            ans += (n - dan) * it;
        }
        else
        {
            k--;
            it = it2;
            ans = sum2;
            if ((n - it) == 1)
                ans += (n - it) * it;
            else
            {
                if (k & 1)
                    ans += (n - it) * it;
                else
                    ans += (n - it) * (it + 1);
            }
        }
    }
    cout << ans << '\n';
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

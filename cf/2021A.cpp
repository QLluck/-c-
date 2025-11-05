#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define pii pair<int, int>
#define fi first
#define se second
const int N = 5e5 + 7;
int a[N] = {0};

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int sum = a[1];
    int num = 1;
    for (int i = 2; i <= n; i++)
    {
        sum += num * a[i];
        num *= 2;
    }
    int ans = sum / (num);
    cout << ans << endl;
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    // int a = ((1LL << 50) * 1000000000LL);
    // cout
    // << ((1LL << 50) * 1000000000LL) << endl;
    cin >> t;
    while (t--)
        solve();
}

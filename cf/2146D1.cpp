#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>
#define fi first
#define se second
const int N = 2e5 + 7;
int a[N];
int dp[N];

void init()
{
    int sum = 1;
    for (int i = 0; i <= 32; i++)
    {
        dp[i] = sum;
        sum *= 2;
        sum += 1;
    }
}
void solve()
{
    int l, r;
    cin >> l >> r;
    int sum = (l + r) * (r - l + 1);
    for (int i = l; i <= r; i++)
        a[i] = i;
    map<int, int> me;
    for (int i = r; i >= 1; i--)
    {

        int num = log2(a[i]);
        int y = dp[num];
        // cout << i << ' ' << y << '\n';
        if (me[y - a[i]] || me[a[i]])
            continue;

        me[y - a[i]] = 1;
        me[a[i]] = 1;
        swap(a[i], a[y - a[i]]);
    }
    cout << sum << '\n';
    for (int i = l; i <= r; i++)
        cout << a[i] << ' ';
    cout << '\n';
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
// 000 001 010 011 100 101 110 111 1000
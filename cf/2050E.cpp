#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
const int N = 3e3 + 7;
int me[N];
int dp[N][N];
int pix[N] = {0};
int s2(string &a, string &b, string &c)
{
    int n = a.size() + b.size();
    int ita = 0;
    int itc = 0;
    int ans = 0;
    for (int i = 0; i <= n; i++)
        me[i] = 0;

    while (ita < a.size() && itc < c.size())
    {
        // cout << a[ita] << ' ' << c[itc] << ' ' << ita << ' ' << itc << '\n';
        if (a[ita] == c[itc] && !me[itc])
            ans++, ita++, me[itc] = 1, itc++;
        else
            itc++;
    }
    int itb = 0;
    itc = 0;
    while (itb < b.size() && itc < c.size())
    {
        if (b[itb] == c[itc] && !me[itc])
            ans++, itb++, me[itc] = 1, itc++;
        else
            break;
    }
    return n - ans;
}
void solve()
{
    string a, b, c;
    cin >> a >> b >> c;
    // cout << a << '\n';
    // cout << b << '\n';
    // cout << c << '\n';
    a = "**" + a;
    b = "**" + b;
    c = "*" + c;
    int n = a.size();
    int m = b.size();
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            dp[i][j] = 1e9 + 7;
    dp[1][1] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (i == 1 && j == 1)
                continue;
            // cout << i << ' ' << j << ' ' << i + j - 2 << ' ' << a[i] << ' ' << b[j] << ' ' << c[i + j - 2] << '\n';
            // cout << dp[i][j] << '\n';
            if (i >= 2)
            {
                // cout << dp[i-1][j] << '\n';
                int du = (dp[i - 1][j] + ((a[i] == c[i + j - 2]) ? 0 : 1));
                // cout << ' ' << dp[i - 1][j] << ' ' << "du " << du << ' ' << (dp[i - 1][j] + (a[i] == c[i + j - 2]) ? 0 : 1)<<'\n';
                dp[i][j] = min(du, dp[i][j]);
                // cout<<du<<' ' << dp[i - 1][j] <<' '<< dp[i][j] << '\n';
            }
            if (j >= 2)
            {

                int dl = dp[i][j - 1] + ((b[j] == c[i + j - 2]) ? 0 : 1);
                dp[i][j] = min(dl, dp[i][j]);
                // cout << dp[i][j] << '\n';
            }
            // cout << dp[i][j] << '\n';
        }
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= m; j++)
    //     {
    //         cout << dp[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    cout << dp[n - 1][m - 1] << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}
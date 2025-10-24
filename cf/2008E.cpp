#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
const int N = 2e5 + 7;
pii a[N][26][2];

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = '*' + s;
    for (int i = 0; i < 26; i++)
    {
        a[0][i][1].fi = 0, a[n + 1][i][1].se = 0;

        a[0][i][0].fi = 0, a[n + 1][i][0].se = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 26; j++)
        { 
            a[i][j][1].fi = a[i - 1][j][1].fi;
            a[i][j][0].fi = a[i - 1][j][0].fi;

        }
        a[i][s[i] - 'a'][i&1].fi++;
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = 0; j < 26; j++)
        {
            a[i][j][1].se = a[i + 1][j][1].se;
            a[i][j][0].se = a[i + 1][j][0].se;
        }
        a[i][s[i] - 'a'][i & 1].se++;
    }
    // for (int i = 1; i <= n;i++)
    // {
    //     for (int j = 0; j < 26;j++)
    //         cout << a[i][j][0].fi << ' ';
    //     cout << '\n';
    // }
        if (!(n & 1))
        {
            int ma1 = 0;
            int ma0 = 0;
            for (int i = 0; i < 26; i++)
            {
                ma1 = max(ma1, a[n][i][1].fi);
                ma0 = max(ma0, a[n][i][0].fi);
            }
            int ans = n - ma0 - ma1;
            // cout << ma1 << ' ' << ma0 << '\n';
             cout << ans << '\n';
            return;
        }
  
    int ans = 1e18 + 7;
    for (int i = 1; i <= n;i++)
    {
        int ma1 = 0;
        int ma0 = 0;
        for (int j = 0; j < 26; j++)
        { 

            ma1 =max(ma1,  a[i-1][j][1].fi + a[i + 1][j][0].se);
            ma0 = max(ma0, a[i - 1][j][0].fi + a[i + 1][j][1].se);
            
        }
        ans = min(ans, (n - 1) - ma1 - ma0);
    }
    // cout << ma1 << ' ' << ma0 << '\n';
    //  ans = (n - 1) - ma1 - ma0;
    ans++;
    cout << ans << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}

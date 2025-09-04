#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
const int N = 5e5 + 7;
vector<int> a[507];
int ans[507], it;
void solve()
{
    int n;
    cin >> n;

    it = 0;
    for (int i = 1; i <= n; i++)
        a[i].clear();
    int ma = 0;
    for (int i = 1; i <= n; i++)
    {
        cout << '?' << ' ' << i << ' ' << n;
        // fflush(stdout);
        for (int j = 1; j <= n; j++)
        {
            cout << ' ' << j;
            // fflush(stdout);
        }
        cout << endl;

        fflush(stdout);
        int num;
        cin >> num;
        ma = max(ma, num);
        a[num].push_back(i);
    }
    it++;
    ans[it] = a[ma][0];
    for (int i = ma - 1; i >= 1; i--)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            cout << '?' << ' ' << ans[it] << ' ' << 2 << ' ' << ans[it] << ' ' << a[i][j] << endl;
            // fflush(stdout)
            int num;

            cin >> num;
            if (num)
            {
                ans[++it] = a[i][j];
                break;
            }
        }
    }
    cout << '!' << ' ' << it;
    // fflush(stdout);
    for (int i = 1; i <= it; i++)
    {
        cout << ' ' << ans[i];
        //   fflush(stdout);
    }
    cout << endl;
    // fflush(stdout);
}
signed main()
{
    // ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}

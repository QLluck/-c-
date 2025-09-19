#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
const int N = 5e5 + 7;

int a[N];
int b[N],it;
void solve()
{
    int n,k;
    cin >> n>>k;
    int ma = 0;
    for (int i = 1; i <= n;i++)
     {   cin >> a[i];
         ma = max(a[i], ma);
     }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= ma;i++)
    {
        it = 0;
        int sum = 0;
        for (int j = 1; j <= n;j++)
        {
            b[++it] = abs(i - a[j]);
            sum += b[it];
        }

        cout << sum<<' ';
       
    }
    cout << '\n';
}
signed main()
{
    // ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}

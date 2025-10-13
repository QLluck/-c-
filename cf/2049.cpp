#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
const int N = 5e5 + 7;
int ans[N];
void solve()
{
    int n, x, y;
    cin >> n >> x >> y;
    if(n&1)
    {
        ans[y] = 2;
        int f = 0;
        for (int i = 1; i <= n - 1;i++)
        {
            int it = i + y;
            
            if(it>n)
                it = it % n ;
            // cout << it << '\n';
            ans[it] = f;
            f = !f;
        }
    }
    else 
    {
        int f = 0;
        for (int i = 1; i <= n;i++)
            ans[i] = f, f = !f;
        if(ans[x]==ans[y])ans[y]=2;

    }
    for (int i = 1; i <= n;i++)
        cout << ans[i] << ' ';
    cout << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}
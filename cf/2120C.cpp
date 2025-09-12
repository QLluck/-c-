#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
const int N = 1e6 + 7;
pii a[N];
pii b[N];

int n, k;
int ans[N], ita;
int check(int mid)
{
    return  (n + n - mid + 1) * mid / 2  <= k ;
}
void solve()
{
   
    cin >> n >> k;
    for (int i = 1; i <= n;i++)
        ans[i] = 0;
            if (k < n || k > (n * (n + 1) / 2))
            {
                cout << -1 << '\n';
                return;
            }
    int l = 0;
    int r = n + 1;
    while(l+1<r)
    {
        int mid = (l + r) >> 1;
        if(check(mid))
            l = mid;
            else
                r = mid;
    }
    int ji = (n + n - l + 1) * l / 2 ;
    int duo = k - ji;
    int it = l+1;
    ans[duo + 1] = l;
    //3 3 2 1
    //cout << l << ' ' << it << '\n';
    for (int i = n; i >= n - l+2;i--)
      {  ans[i] = n-i + 1;
         // cout << i << '\n';
      }

    // for (int i = 1; i <= n; i++)
    //     cout << ans[i] << ' ';
   // cout << '\n';
    for (int i = 1; i <= n;i++)
    if(ans[i]==0)
            ans[i] = it++;
    cout << ans[1] << '\n';
    for (int i = 1; i < n;i++)
        cout << ans[i] << ' '<<ans[i+1]<<'\n';
   // cout << '\n';
}

    signed main()
    {
        ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
        int t;
        cin >> t;
        while (t--)
            solve();
        // cout << 1 << ' ' << 3 << '\n';
        //  for (int i = 1; i <= 10; i++)
        //  {
        //      cout << po(3, i) << ' ' <<w(i)<<' '<<w(i+1)-3*w(i) << '\n';
        //  }
    }
//

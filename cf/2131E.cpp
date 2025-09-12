#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
const int N = 5e5 + 7;
int a[N];
int b[N];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> a[i];
    for (int i = 1; i <= n;i++)
        cin >> b[i];
    a[n + 1] = 0;
    b[n + 1] = 0;
    b[0] = 0;
    a[0] = 0;
    for (int i = n; i >=1;i--)
    {
         if(a[i]==b[i])
             continue;
          if((a[i]^a[i+1])!=b[i] && (a[i]^b[i+1])!=b[i])
          {
              cout << "NO" << '\n';
              return;
             // break;
          }
    }

 
        cout << "YES" << '\n';
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

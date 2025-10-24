#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
const int N = 2e5 + 7;
const int mod = 1e9 + 7;
int a[N];
int jie[N];
int po(int a,int b)
{
    int res = 1;
    while(b)
    {
        if(b&1)
        {
            res *= a;
            res %= mod;
        }
        b >>= 1;
        a *= a;
        a %= mod;
    }
    return res;
}
void init()
{
    jie[0] = 1;
    for (int i = 1; i <N;i++)
     {   jie[i] = jie[i - 1] * i;
         jie[i] %= mod;
     }
}
void solve()
{
    int n,k;
    cin >> n>>k;
    int ans = 0;
    k /= 2;
    int n1 = 0;
    int n0 = 0;
    for (int i = 1; i <= n;i++)
       { cin >> a[i];
        if(a[i])
            n1++;
        else
            n0++;
       }
       int sum =1;
       sum *= jie[n1];
       sum %= mod;
       sum *= jie[n0];
       sum %= mod;
       for (int i = 1; i <= n; i++)
       {
           int l = i;
           int r = k - i;

           int chu = 1;
           if ((0 <= i && i <= n1) && (0 <= r && r <= n0) &&(i<=k))
           {
               chu *= jie[n - i];
               chu %= mod;
               chu *= jie[i];
               chu %= mod;
               chu *= jie[n0 - k + i];
               chu %= mod;
               chu *= jie[k - i];
               chu %= mod;
           }
           ans += (sum * po(chu, mod - 2) % mod);
           ans %= mod;
    }
    cout << ans << '\n';
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

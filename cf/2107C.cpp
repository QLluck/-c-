#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+7;
int a[N] = {0};
int qu[N] = {0};
int dp[N] = {0};
int n, k;
int check(int mid,int f)
{
    int ma = -1e18;
    for (int i = 1; i <= n;i++)
    {
        if(i==f)
            dp[i] = max(dp[i - 1] + mid, mid);
        else
            dp[i] = max(dp[i - 1] + a[i], a[i]);
        ma = max(dp[i], ma);
    }
    return ma < k;
}
void solve()
{
    
    cin >> n >> k;
    string s;
    cin >> s;
    s = '1' + s;
    for (int i = 1; i <= n;i++)
        cin >> a[i],dp[i]=0;
    int ma = -1e18;
    int f =  0 ;
    for (int i = 1; i <= n;i++)
    {
        if(s[i]=='1')
           { dp[i] = max(dp[i - 1] + a[i], a[i]);

           }
            else
            {
                a[i] = -1e12;
                dp[i] = max(dp[i - 1] + a[i], a[i]);
                // a[i] = -1e12;
                f = i;
            }
            ma = max(ma, dp[i]);
    }

    if(ma>k)
       { cout << "No" << '\n';
           return;
       }
       else if(ma<k&&f==0)
       {
           cout << "No" << '\n';
           return;
       }
       else if (ma == k)
       {
           cout << "Yes" << '\n';
        //    for (int i = 1; i <= n; i++)
        //        if (s[i] == '0')
        //            a[i] = -1e14;
           // cout << '\n';
       }
            else if(f&&ma<k)
             {   cout << "Yes" << '\n';

                 int l = -4e17;
                 int r = 4e17;
                 while(l+1<r)
                 {
                     int mid = (l + r) >> 1;
                     if(check(mid,f)) l = mid;
                     else r = mid;
                 }
                 a[f] = r;
                //  for (int i = 1; i <= n; i++)
                //      cout << a[i] << ' ';
                //  cout << '\n';
                //  for (int i = 1; i <= n;i++)
                //      cout << "pan" << '\n';
             }
             ma = -1e18;
            //  for (int i = 1; i <= n;i++)dp[i]=max(dp[i-1]+a[i],a[i]),ma=max(ma,dp[i]);
            //  cout << (ma == k) << '\n';
             for (int i = 1; i <= n;i++)
                 cout << a[i] << ' ';
             cout << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
    
    //printb(2);
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
const int N = 3e5 + 7;
int a[N];
pii b[N];
pii ma[N];
bool f(pii a,pii b)
{
    if(a.fi!=b.fi)
        return a.fi < b.fi;
    else
        return a.se < b.se;
}
void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = '*' + s;
    int itb = 0;
    for (int i = 1; i <= n;i++)
     {   cin >> a[i];
        if(s[i]=='B')
        {
            b[++itb].fi = a[i];
            b[itb].se = i;
        }
     }
     if(itb<=k)
     {
         cout << 0 << '\n';
         return;
     }
    //  stack<int> sta;
    //  for (int i = 1; i <= n;i++)
    //  {
    //     while(sta.size()&&a[sta.top()]>a[i])
    //     {
    //         if (s[i] == 'B' && s[sta.top()] == 'R')
    //             ma[i].fi = sta.top();
    //         sta.pop();
    //     }
    //     sta.push(i);
    //  }
    //  while(sta.size())
    //      sta.pop();
    //  for (int i = n; i >= 1;i--)
    //  {
    //     while(sta.size()&&a[sta.top()]>a[i])
    //     {
    //         if(s[i]=='B'&&s[sta.top()]=='R')
    //             ma[i].se = sta.top();
    //         sta.pop();
    //     }
    //     sta.push(i);
    //  }
    //  while(sta.size())
    //      sta.pop();
     sort(b + 1, b + itb + 1);
     int l=1e9+7, r=0;
     

     int tma = 0;
     while(itb>=1&&k)
     {
         if(l==1e9+7&&r==0)
         {
             l =  b[itb].se;
              r =  b[itb].se;
         }
         if (itb > 1)
        {
             int l1 = min(l, b[itb - 1].se);
             int r1 = max(r, b[itb - 1].se);
            int ma = 0;
            for (int i = l1+1; i < l;i++)
            {
                ma = max(ma, a[i]);
            }
            for (int i = r+1; i < r1; i++)
            {
                ma = max(ma, a[i]);
            }
          // cout << l1 << ' ' << r1 << ' ' << ma << '\n';
            if(ma<b[itb-1].fi&&ma<b[itb].fi)
             {   
                tma = max(ma, tma);
                 itb--;
                 l = l1;
                 r = r1;
                 //  k--;
             }
            else
             {   k--;
                 itb--;
                 l = 1e9 + 7;
                 r = 0;
             }
         }
         else 
         {
             itb--;
             k--;
         }
        
     }
     cout << max(b[itb].fi, tma) << '\n';
}

// 446
// 1 2
//
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
 
    cin >> t;
    while (t--)

        solve();
    // test();

    // printb(2);
}
// 4 3 3  2 1
// 4 2 3 1 3
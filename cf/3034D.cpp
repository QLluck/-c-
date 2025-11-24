#include <bits/stdc++.h>
using namespace std;
#define int long long
#define PII pair<int, int>
#define fi first
#define se second
const int N = 2e5 + 7;
int a[N];
int me[N];
PII ans[N];
int it = 0;
void solve()
{
    int n;
    cin >> n;
    it = 0;
    queue<PII> que;
    for (int i = 1; i <= n;i++)
     {   cin >> a[i];
        if(a[i]==2)
            que.push({ a[i],i});
     }
     for (int i = n; i >= 1;i--)
     {
        
        if(a[i]==0)
        {
            while(que.size()&&que.front().se>=i  )
                que.pop();
            while(que.size()&& que.front().fi==0)
                que.pop();
            if(que.size())
            {
                int it1 = que.front().se;
                que.front().fi--;
                a[it1]--;
                a[i]++;
                ans[++it].fi = i;
                ans[it].se = it1;
            }
        }
     }
     for (int i = 1; i <= n;i++)
        if(a[i]==1)
             que.push({a[i], i});
    
         for (int i = n; i >= 1; i--)
         {

             if (a[i] == 0)
             {
                 while (que.size() && que.front().se >= i)
                     que.pop();
                 while (que.size() && que.front().fi == 0)
                     que.pop();
                 if (que.size())
                 {
                     int it1 = que.front().se;
                     que.front().fi--;
                     a[it1]--;
                     a[i]++;
                     ans[++it].fi = i;
                     ans[it].se = it1;
                 }
             }
         }
         for (int i = 1; i <= n; i++)
             if (a[i] == 2)
                 que.push({a[i], i});
         for (int i = n; i >= 1; i--)
         {

             if (a[i] == 1)
             {
                 while (que.size() && que.front().se >= i)
                     que.pop();
                 while (que.size() && que.front().fi  <=1)
                     que.pop();
                 if (que.size())
                 {
                     int it1 = que.front().se;
                     que.front().fi--;
                     a[it1]--;
                     a[i]++;
                     ans[++it].fi = i;
                     ans[it].se = it1;
                 }
             }
         }
        //  for (int i = 1; i <= n;i++)
        //      cout << a[i] << ' ';
        //  cout << '\n';
         cout << it << '\n';
         for (int i = 1; i <= it;i++)
             cout << ans[i].fi << ' ' << ans[i].se << '\n';
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();

    // printb(2);
}
// 4 3 3  2 1
// 4 2 3 1 3
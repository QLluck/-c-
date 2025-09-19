#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
const int N = 5e5 + 7;

int a[N];
int b[N];
pii me[N];
int me2[N];
int me3[N];
vector<pii> ans;
void solve()
{
    int n;
    cin >> n;
    int f = 0;
    ans.clear();
    for (int i = 1; i <= n; i++)
        cin >> a[i],me[i].fi=0,me[i].se=0,me2[i]=0,me3[i]=0;
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        me[a[i]].fi = b[i];
        me[a[i]].se = i;
        if (a[i] == b[i])
        {
            if (f)
            {
                f = -1;
                //cout << a[i] << ' ' << b[i] << '\n';
            }
            else
            {
                //cout << a[i] << ' ' << b[i] << '\n';
                f = a[i];
            }
        }
    }
    if(f==-1) 
    {
        cout << -1 << '\n';
        return;
    }
    if((!(n&1)) &&f)
      {  cout << -1 << '\n';
          return;
      }


int it = 0;
for (int i = 1; i <= n; i++)
{   if(me[a[i]].fi==0)
        continue;
    if(a[i]==f)
        continue;
    int tmp = me[a[i]].fi;
    int tmp2 = me[tmp].fi;
    if(tmp2!=a[i])
    {
        cout << -1 << '\n';
        return;
    }
    else 
    {
        me2[++it] = i;
        // me[a[i]].se = it;
        me3[i] = it;
        
        me2[++it] = me[tmp].se;
        me3[me[tmp].se] = it;
        // me[tmp].se = it;
        me[a[i]].fi = 0;
        me[tmp].fi = 0;
    }
}
for (int i = 1; i <= (n & 1 ? n - 1 : n);i++)
{    
     if(i&1)
     {
         int t1 = me2[i];
         int t2 = i/2+1;
         //cout << t1 << ' ' << t2 << '\n';
         if(t1==t2)
             continue;
         ans.push_back({t1, t2});
         me2[me3[t2]] = t1;
     }
     else 
     {
         int t1 = me2[i];
         int t2 = n-(i/2)+1;
         //cout << t1 << ' ' << t2 << '\n';
         if (t1 == t2)
             continue;
         ans.push_back({t1, t2});
         me2[me3[t2]] = t1;
     }
}
cout << ans.size() << '\n';
for (int i = 0; i < ans.size();i++)
    cout << ans[i].fi << ' ' << ans[i].se << '\n';
}

signed main()
{
    // ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}

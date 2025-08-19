#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
const int N = 5e5+7;
pair<int,pii> a[N];
pii pix[N];
int ans[N],it;
void solve()
{

  int n;
  cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i].fi>>a[i].se.fi,a[i].se.se=i;
    int l =0;
    int r =0 ;
    it=0;
    //ans[++it]=1;
    sort(a+1,a+n+1);

    for(int i=1;i<=n;i++)
    {
         if(l==a[i].fi)
         {
            if(a[i].se.fi>r)r=a[i].se.fi,ans[it]=a[i].se.se;
         }
         else 
         {
             l=a[i].fi;
             r=a[i].se.fi;
             ans[++it]=a[i].se.se;
         }
    }
    cout<<it<<'\n';
    for(int i=1;i<=it;i++)cout<<ans[i]<<' ';
    cout<<'\n';
  

    
}
signed main()
{
    ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}

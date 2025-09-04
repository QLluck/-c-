#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define se second
const int N = 2e6+7;
pii a[N];
int b[N],it;
int t[N]={0};
mt19937_64 rng(random_device{}());

void solve()
{   int n;
    cin>>n;
    it =0 ;
    for(int i=1;i<=n;i++)
    {
          cin>>a[i].fi>>a[i].se;
          a[i].se++;
          b[++it] = a[i].fi ;
          b[++it] = a[i].se;
    }
    sort(b+1,b+it+1);
    it = unique(b+1,b+it+1)-b-1;
    for(int i=1;i<=it;i++)t[i]=0;
    for(int i =1;i<=n;i++)
    {
          a[i].fi = lower_bound(b+1,b+it+1,a[i].fi)-b;
          a[i].se = lower_bound(b+1,b+it+1,a[i].se) -b;
          unsigned long long x = rng();
          t[a[i].fi]^=x ;
          t[a[i].se ]^=x ;
    }

    for(int i=1;i<=it;i++)t[i]^=t[i-1];
    t[++it]=0;
    sort(t+1,t+it+1);
    int ans = unique(t+1,t+it+1)-t-1;
    cout<<ans<<'\n';

    
}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();

}
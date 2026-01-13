#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define PII  pair<int,int> 
#define fi first 
#define se second 
const int N = 1e5+7;
PII a[N];
void solve()
{
    int n;
    cin>>n;
    int it =0 ;
    map<int,int>mp;
    
    for(int i=1;i<=n;i++)
    {
        int a1,b1;
        cin>>a1>>b1;
      if(mp[a1]==0)a[++it].fi =a1;
        mp[a1]+=b1;
    }
    sort(a+1,a+it+1);
    for(int i=1;i<=it;i++)a[i].se=mp[a[i].fi];
    int l = 1,r=it;
    int ans= 0 ;
    while(l<r)
    {
        // cout<<l<<' '<<r<<'\n';
        while(l<=it && a[l].se==0)l++;
        while(r>=1 && a[r].se==0)r--;
        if(l<r)
        {
             int mi = min(a[l].se,a[r].se);
             ans += mi * abs(a[l].fi - a[r].fi) ;
             a[l].se-=mi;
             a[r].se-=mi;
        }

    }
    cout<<ans<<'\n';
}
signed main()
{
  ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
  int t;
  t =1;
  cin>>t;
  while(t--)
  solve();
}
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define fi first 
#define se second
#define  PII pair<int,int> 
const int N = 2e6+7;
PII a[N];
bool f(PII a, PII b)
{
    if(a.se!=b.se)return a.se<b.se;
    else return a.fi<b.fi;
}

map<int,int>mp;
int find(int x)
{   if(mp[x]==0)return x;
    else if(x==mp[x])return x;
    else return mp[x]=find(mp[x]);
}
void  solve()
{
    
   int n;
   mp.clear();
   cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i].fi>>a[i].se;
    sort(a+1,a+n+1,f);
    int ans= 0 ;
    int it =0 ;
    for(int i=1;i<=n;i++)
    {
        int l = a[i].fi;
        int r = a[i].se;
        
         if(mp[l]==0)ans++,mp[l]=l+1;
         else 
         {
            int x = find(l);
            if(x<=r)
            { mp[x]=x+1,ans++;
                // cout<<l<<' '<<r<<'\n';
            }
         }

 
    }
    cout<<ans<<'\n';



}


signed main()
{  

    ios::sync_with_stdio(0),cout.tie(0),cout.tie(0);
    int t;
    t =1;
    
    cin>>t;
    while(t--)
    solve();
}
// 1
// 2019 5 12 Monday
// 2019 5 12

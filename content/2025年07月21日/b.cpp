#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6+7;
int t[N]={0};
int a[N]={0};
int b[N]={0};
int me[N]={0};
int ans[N]={0};
int lowbit(int x){return x&-x;}

int n;
void add(int x ,int k)
{    
    
     while(x<=n)
     {
         t[x]+=k;
        // cout<<t[x]<<'\n';

         x+=lowbit(x);
     }
}
int query(int x)
{
     int res=0 ;
     while(x)
     {
         res += t[x];
         x-=lowbit(x);
     }
     return res;
}
void solve()
{
      
      cin>>n;
     for(int i =1;i<=n;i++)t[i]=0;
      for(int i=1;i<=n;i++)cin>>a[i],me[a[i]] =n-i+1 ,ans[a[i]] = i-1;

      for(int i =1;i<=n;i++)cin>>b[i];
      for(int i =1;i<=n;i++)
      {
         
         ans[b[i]] += query(me[b[i]]);
        // cout<<b[i]<<' '<<query(me[b[i]])<<' '<<me[b[i]]<<'\n';

         add(me[b[i]],1);
      }
      for(int i =1;i<=n;i++)cout<<ans[i]<<' ';
      cout<<'\n';
    
}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    solve();
}
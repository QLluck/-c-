#include<bits/stdc++.h>
using namespace std ;
#define int long long 
#define fi first
#define se second 
#define PII pair<int,int>
const int N = 2e6+7;
const int mod = 998244353;
int a[N];
int d[N];
int b[N]; 
int ans[N];
void solve()
{
  int n;
  cin>>n;
  for(int i=1;i<=2*n+2;i++)cin>>a[i];
  int it =0 ;
//   for(int i=3;i<=2*n+2;i+=2)
//   {
//       ++it;
//       b[it]= (a[i]+1) /2;
//   }
  int f = 0;
  int s=0 ;
//   for(int i=1;i<=it;i++)cout<<b[i]<<' ';
//   cout<<'\n';
  for(int i=3;i<=2*n+1;i++)
  {
      if(a[i]==1 && (i%2==0) )s=i;
  }
//   cout<<s<<'\n';
  if(s==0)
  {
    for(int i=1;i<=n;i++)cout<<'a';
  }
  else 
  {
     ans[s]=1;
     ans[s+1]=0;
     ans[s-1]=1;
     for(int i=s-1;i-1>=1;i--)
     {
        if(i%2!=0)continue;
        if(a[i]!=1)ans[i-1]=ans[i+1];
        else ans[i-1]=!ans[i+1];
     }
     for(int i=s+1;i+1<=n;i++)
     {
        if(i%2!=0)continue;
        if(a[i]!=1)ans[i+1]=ans[i-1];
        else ans[i+1]=!ans[i-1];
     }
    //  for(int i=1;i<=2*n+2;i++)cout<<ans[i]<<' ';
    //  cout<<'\n';
     for(int i=2;i<=2*n+2;i++)if(i%2==1)cout<<(ans[i]?'a':'b');
     cout<<'\n';
  }

  


   
   
}
//aaaaaa

signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    t=1;
    while(t--)solve();
}
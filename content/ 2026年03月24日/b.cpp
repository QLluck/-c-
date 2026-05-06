#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define fi first
#define se second 
#define PII pair<int,int>
const int N = 5e5+7;

int me[N];
int dp[1000][1000];
pair<double,PII> a[N];
void solve()
{
  int n,m;
  cin>>n;
  cin>>m;
  for(int i=1;i<=n;i++)
  {
    int v,w;
    double b;
    cin>>v>>w;
   b = (double)w/(double)v;
   a[i].fi=b,a[i].se.fi=v,a[i].se.se=w;
  }
  sort(a+1,a+n+1);
  double ans =0 ;

  for(int i=n;i>=1;i--)
  {
    ans += min(m*a[i].fi,a[i].fi*a[i].se.fi);
    m-=min(a[i].se.fi,m);
      
  }
  cout<<ans<<'\n';
 

    
}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);

    int t;
    t=1;
    // cin>>t;
    while(t--)
    solve();
}
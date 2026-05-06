#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define fi first
#define se second 
#define PII pair<int,int>
const int N = 5e5+7;

// int a[N][N];
PII a[N];
int b[N];
int n,m;
int mi,ma;
bool f(PII a,PII b)
{
    return a.se>b.se;
}
int ans =0 ;
bool f2(PII a, PII b){return a.fi<b.fi ;}
void dfs(int d,int x ,int s,int sum,int z)
{
    ans =max(ans,z);
    if(d>n)return;
    if(s>=a[d].first)
    dfs(d+1,x+1,s-a[d].fi,sum+a[d].se,z+sum);
    
    dfs(d+1,x,s,sum,z);
}
void solve()
{
  cin>>n>>m;
  for(int i=1;i<=n;i++)cin>>a[i].fi;
  for(int i=1;i<=n;i++)cin>>a[i].se;
  sort(a+1,a+n+1,f2);
  int sum = m;
  ma=0;
  mi=0;
  for(int i=1;i<=n;i++)
  {
    sum-=a[i].fi;
    if(sum<0)break ;
    ma++;
  }
  sum=m;
  for(int i=n;i>=1;i--)
  {
    sum-=a[i].fi;
    if(sum<0)break;
    mi++;
  }

sort(a+1,a+n+1,f);
dfs(1,0,m,0,0);
cout<<ans<<'\n';

//   int ans =0 ;
  
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
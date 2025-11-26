#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define PII pair<int,int>
#define fi first 
#define se second 
const int N = 2e5+7;
PII a[N];
int b[N];
int b1[N];
int it;
void solve()
{
  int n;
  cin>>n;
  for(int i=1;i<=n;i++)
  { cin>>a[i].fi>>a[i].se;
    if(a[i].fi<a[i].se)swap(a[i].fi,a[i].se);
  }
  sort(a+1,a+n+1);
  int sum =0 ;
  for(int i=1;i<=n;i++)
  {
    sum+=a[i].se;

  }
  int ans = sum*2;
  ans+=2*a[n].fi;
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
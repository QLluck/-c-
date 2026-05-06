#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define PII pair<int,int>
#define fi first 
#define se second 
const int N = 1e5+7;
vector<int> t[N];
int a[N],ita;
int b[N],itb;
queue<int> que;
map<int,int>me;
// map<int,int>mp;


void solve()
{
  int n;
  cin>>n;
  ita=0,itb=0;
  for(int i=1;i<=n;i++)cin>>a[i];
  for(int i=1;i<=n;i++)
  {
     if(i>1 && a[i]<a[i-1])continue;
     if(i<n&&a[i]<a[i+1])continue;
     b[++itb]=a[i];
  }
  int ans =1;
  if(n==1)
  {
    cout<<0<<'\n';
    return;
  }
  if(itb==1)itb--;
//   int it =0 ;
  while(itb)
  {
    ans++;
      ita=0;
      for(int i=1;i<=itb;i++)a[++ita]=b[i];
      itb=0;
    for(int i=1;i<=ita;i++)
  {
     if(i>1 && a[i]<a[i-1])continue;
     if(i<ita&&a[i]<a[i+1])continue;
     b[++itb]=a[i];
  }
    if(itb==1)itb--;
  }

  cout<<ans<<'\n';
  
  
}
signed  main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    int t;
    t=1;
    // cin>>t;
    while(t--)
    solve();
}
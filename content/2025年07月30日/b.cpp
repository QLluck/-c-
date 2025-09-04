#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int P = 1e9+7;
const int N = 1007;
int me[300]={0};

void solve()
{
  int n;
  cin>>n;
  string s;
  cin>>s;
  s = ' ' + s;
  int ans =0 ;
  int ma =0 ;
  for(int i= 1;i<=200;i++)me[i]=-1e9-7;
  for(int i=1;i<=n;i++)
  {
     ans++;
     if( i-me[s[i]] <=2) ans = i - me[s[i]];
     me[s[i]] = i ;
     ma = max(ans,ma);
  }
  cout<<ma<<'\n';
}
signed main()
{
    ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
    solve();
}
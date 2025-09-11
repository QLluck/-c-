#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+7;
int x[N]={0};
int xx[N]={0};
int xxo[N]={0};
int xxoo[N]={0};
void solve()
{
  int n;
  cin>>n;
  string s;
  cin>>s;
  s = '*'+s;
  for(int i=1;i<=n;i++)
  {
      if(s[i]=='X')
      {
          x[i]=x[i-1]+1;
          xx[i] = xx[i-1]+x[i-1];
          xxo[i] = x[i-1];
          xxoo[i]=xxoo[i-1];
      }
      else if(s[i]=='O')
      {
         x[i]=x[i-1];
         xx[i]=xx[i-1];
         xxo[i]= xxo[i] +=xx[i-1];
         xxoo[i]=xxoo[i]+xxo[i-1];
      }
  }
  cout<<xxoo[n]<<'\n';
}
signed main()
{
  ios::sync_with_stdio(0),cout.tie(0),cin.tie(0);
  solve();
}